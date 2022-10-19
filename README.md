# VideoEncoder
视频编码器 支持动态宽高视频 自适应填充至画面 支持双路音频混流处理 支持传入不同采样率音频数据



# Usage 

- 创建编码器

````
auto encoder = ezcode::VideoEncoder::create(1920, 1080, "D:/test.avi");
````

- 检查是否存在错误
````
bool error = encoder->checkHasError();
if(error){
    //编码器初始化错误
}else{
    //编码器初始化正常
}
````


- 编码一帧视频

````
encoder->encodeVideo(buffer, bufferSize, frameWidth, frameHeight);   
````

- 编码一组PCM音频数据

````
encoder->encodeAudio(buffer, bufferSize, 44100, 1);
````

- 结束编码， 释放所有编码器

````
encoder->finishEncoder();
````

- 释放所有资源

````
encoder->release();
````
