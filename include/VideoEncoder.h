#pragma once

#define API_DLL_EXPORT __declspec(dllexport)

namespace ezcode {

	enum AudioInputType
	{
		/// <summary>
		/// 主音频
		/// </summary>
		AudioInputTypeMain,

		/// <summary>
		/// 第二音频
		/// 若存在主音频，则混音处理
		/// </summary>
		AudioInputTypeMix,
	};


	class API_DLL_EXPORT VideoEncoder
	{
	public:
		/// <summary>
		/// 创建编码器 (第1步)
		/// </summary>
		/// <param name="video_width">输出视频宽</param>
		/// <param name="video_height">输出视频高</param>
		/// <param name="file_path">视频输出路径</param>
		/// <returns></returns>
		static VideoEncoder* create(int video_width, int video_height, const char *file_path);



		/// <summary>
		/// 检查是否存在错误 (第2步)
		/// </summary>
		/// <returns>true 有错误， false 无错误</returns>
		virtual bool checkHasError() = 0;


		/// <summary>
		/// 编码一帧视频 (第3步)
		/// </summary>
		/// <param name="data">数据 只支持 YUV420 数据</param>
		/// <param name="dataLen">数据长度</param>
		/// <param name="width">帧视频宽</param>
		/// <param name="height">帧视频高</param>
		virtual void encodeVideo(void* data, int dataLen, int width, int height) = 0;
		/// <summary>
		/// 编码一组PCM音频数据 (第3步)
		/// </summary>
		/// <param name="data">数据体, 只支持PCM数据 AV_SAMPLE_FMT_S16 格式</param>
		/// <param name="dataLen">数据长度</param>
		/// <param name="audio_rate">音频采样率</param>
		/// <param name="audio_channels">声道数</param>
		/// <param name="type">音频类型</param>
		virtual void encodeAudio(void* data, int dataLen, int audio_rate, int audio_channels, AudioInputType type = AudioInputTypeMain) = 0;

		/// <summary>
		/// 结束编码， 释放所有编码器 (第4步)
		/// </summary>
		virtual void finishEncoder() = 0;

		/// <summary>
		/// 释放所有资源 (第5步)
		/// </summary>
		virtual void release() = 0;
	};
}

