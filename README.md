# VideoEncoder
视频编码器 实时编码 支持动态宽高视频 自适应填充至画面 支持双路音频混流处理 支持传入不同采样率音频数据



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
// 默认主音频
encoder->encodeAudio(buffer, bufferSize, 44100, 1);
//可添加混流音频流，代码如下：
encoder->encodeAudio(buffer, bufferSize, 44100, 1, ezcode::AudioInputTypeMix);

````

- 结束编码， 释放所有编码器

````
encoder->finishEncoder();
````

- 释放所有资源

````
encoder->release();
````


### 仅供个人学习交流使用， 若商用请联系作者授权 ！
