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
        $this->assertEquals("", (string) $stream);
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
        $this->assertEquals("", (string) $stream);
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
}

