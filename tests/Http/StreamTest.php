<?php

namespace Unit\Http;

use Unit\TestCase;
use Arango\Http\Base\Stream;
use Arango\Http\Contracts\Stream as StreamInterface;

class StreamTest extends TestCase
{
    /**
     * @var \Arango\Http\Base\Stream
     */
    protected $instance;

    /**
     * @var resource|null
     */
    protected $tempFile = null;

    public function setUp()
    {
        $this->instance = new Stream(tmpfile(), Stream::MODE_READ_WRITE_FROM_BEGIN);
    }

    public function tearDown()
    {
        if ($this->tempFile && is_file($this->tempFile)) {
            unlink($this->tempFile);
        }
    }

    public function makeTemporaryFile()
    {
        return $this->tempFile = tempnam(sys_get_temp_dir(), "arango");
    }

    /**
     * @covers \Arango\Http\Base\Stream::__construct()
     */
    public function testConstruct()
    {
        $resource = tmpfile();
        $stream = new Stream($resource);

        $this->assertInstanceOf(StreamInterface::class, $stream);
        $this->assertEquals($resource, $stream->getResource());
    }

    /**
     * @covers \Arango\Http\Base\Stream::__toString()
     */
    public function testToString()
    {
        $str = "Foobar";

        $byteSize = strlen($str);

        $writed = $this->instance->write($str);

        $this->assertEquals($byteSize, $writed);
        $this->assertTrue($this->instance->isWritable());
        $this->assertEquals($str, (string)$this->instance);

        // Non readable must return empty string
        $this->makeTemporaryFile();
        file_put_contents($this->tempFile, "Foo bar");

        $stream = new Stream($this->tempFile, "w");
        $this->assertEquals("", (string)$stream);
    }

    /**
     * @covers \Arango\Http\Base\Stream::close()
     */
    public function testClose()
    {
        $this->makeTemporaryFile();

        $resource = fopen($this->tempFile, Stream::MODE_READ_WRITE_RESET);

        $stream = new Stream($resource);
        $stream->write("Foo bar");

        $stream->close();

        $this->assertFalse(is_resource($resource));
        $this->assertAttributeEmpty('streamResource', $stream);
        $this->assertEquals("", (string)$stream);
    }

    /**
     * @covers \Arango\Http\Base\Stream::detach()
     */
    public function testDetach()
    {
        $resource = fopen("php://memory", Stream::MODE_READ_WRITE_RESET);

        $stream = new Stream($resource);

        $this->assertSame($resource, $stream->detach());
        $this->assertAttributeEmpty('streamResource', $stream);
        $this->assertAttributeEmpty('stream', $stream);
    }

    /**
     * @covers \Arango\Http\Base\Stream::getSize()
     */
    public function testGetSize()
    {
        $this->makeTemporaryFile();

        $str = "show must go on";
        file_put_contents($this->tempFile, $str);

        $resource = fopen($this->tempFile, Stream::MODE_READ_ONLY_FROM_BEGIN);

        $stream = new Stream($resource);

        $this->assertEquals(strlen($str), $stream->getSize());
    }

    /**
     * @covers \Arango\Http\Base\Stream::tell()
     */
    public function testTell()
    {
        $this->makeTemporaryFile();
        $str = "show must go on";
        file_put_contents($this->tempFile, $str);

        $resource = fopen($this->tempFile, Stream::MODE_READ_ONLY_FROM_BEGIN);

        $stream = new Stream($resource);

        fseek($resource, 2);

        $this->assertEquals(2, $stream->tell());

        $this->expectException(\RuntimeException::class);
        $stream->detach();
        $stream->tell();
    }

    /**
     * @covers \Arango\Http\Base\Stream::eof()
     */
    public function testEof()
    {
        $this->makeTemporaryFile();
        $str = "foo bar";
        file_put_contents($this->tempFile, $str);

        $resource = fopen($this->tempFile, Stream::MODE_READ_ONLY_FROM_BEGIN);

        $stream = new Stream($resource);

        fseek($resource, 2);

        $this->assertFalse($stream->eof());

        while (!feof($resource)) {
            fread($resource, 4096);
        }

        // Read all
        $this->assertTrue($stream->eof());

        $stream->rewind();
        $stream->read(8);

        $this->assertTrue($stream->eof());

        // Seek
        $stream->rewind();
        $stream->seek(8);

        $this->assertFalse($stream->eof());

        // Read
        $stream->read(random_int(1, 6));
        $this->assertTrue($stream->eof());
    }

    /**
     * @covers \Arango\Http\Base\Stream::isSeekable()
     */
    public function testIsSeekable()
    {
        $this->makeTemporaryFile();
        $str = "foo bar";
        file_put_contents($this->tempFile, $str);

        $resource = fopen($this->tempFile, Stream::MODE_READ_ONLY_FROM_BEGIN);

        $stream = new Stream($resource);

        $this->assertTrue($stream->isSeekable());
    }

    /**
     * @covers \Arango\Http\Base\Stream::seek()
     */
    public function testSeek()
    {
        $this->makeTemporaryFile();
        $str = "foo bar";
        file_put_contents($this->tempFile, $str);

        $resource = fopen($this->tempFile, Stream::MODE_READ_ONLY_FROM_BEGIN);

        $stream = new Stream($resource);

        $stream->seek(2);
        $this->assertEquals(2, $stream->tell());

        $stream->seek(2, SEEK_CUR);
        $this->assertEquals(4, $stream->tell());

        $stream->seek(-1, SEEK_END);
        $this->assertEquals(6, $stream->tell());
    }

    /**
     * @covers \Arango\Http\Base\Stream::rewind()
     */
    public function testRewind()
    {
        $this->makeTemporaryFile();
        $str = "foo bar";
        file_put_contents($this->tempFile, $str);

        $resource = fopen($this->tempFile, Stream::MODE_READ_WRITE_RESET);

        $stream = new Stream($resource);

        $stream->seek(random_int(1, 6));
        $stream->rewind();

        $this->assertEquals(0, $stream->tell());
    }

    /**
     * @covers \Arango\Http\Base\Stream::isWritable()
     */
    public function testIsWritable()
    {
        $stream = new Stream("php://memory", Stream::MODE_READ_ONLY_FROM_BEGIN);
        $this->assertFalse($stream->isWritable());

        $this->makeTemporaryFile();
        $resource = fopen($this->tempFile, Stream::MODE_READ_ONLY_FROM_BEGIN);

        $stream = new Stream($resource);
        $this->assertFalse($stream->isWritable());

        $resource = fopen($this->tempFile, Stream::MODE_WRITE_ONLY_RESET);
        $stream = new Stream($resource);
        $this->assertTrue($stream->isWritable());
    }
}

