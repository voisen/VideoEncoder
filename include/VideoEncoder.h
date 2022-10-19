#pragma once

#define API_DLL_EXPORT __declspec(dllexport)

namespace ezcode {

	enum AudioInputType
	{
		/// <summary>
		/// ����Ƶ
		/// </summary>
		AudioInputTypeMain,

		/// <summary>
		/// �ڶ���Ƶ
		/// ����������Ƶ�����������
		/// </summary>
		AudioInputTypeMix,
	};


	class API_DLL_EXPORT VideoEncoder
	{
	public:
		/// <summary>
		/// ���������� (��1��)
		/// </summary>
		/// <param name="video_width">�����Ƶ��</param>
		/// <param name="video_height">�����Ƶ��</param>
		/// <param name="file_path">��Ƶ���·��</param>
		/// <returns></returns>
		static VideoEncoder* create(int video_width, int video_height, const char *file_path);



		/// <summary>
		/// ����Ƿ���ڴ��� (��2��)
		/// </summary>
		/// <returns>true �д��� false �޴���</returns>
		virtual bool checkHasError() = 0;


		/// <summary>
		/// ����һ֡��Ƶ (��3��)
		/// </summary>
		/// <param name="data">����</param>
		/// <param name="dataLen">���ݳ���</param>
		/// <param name="width">֡��Ƶ��</param>
		/// <param name="height">֡��Ƶ��</param>
		virtual void encodeVideo(void* data, int dataLen, int width, int height) = 0;
		/// <summary>
		/// ����һ��PCM��Ƶ���� (��3��)
		/// </summary>
		/// <param name="data">������, ֻ֧��PCM���� AV_SAMPLE_FMT_S16 ��ʽ</param>
		/// <param name="dataLen">���ݳ���</param>
		/// <param name="audio_rate">��Ƶ������</param>
		/// <param name="audio_channels">������</param>
		/// <param name="type">��Ƶ����</param>
		virtual void encodeAudio(void* data, int dataLen, int audio_rate, int audio_channels, AudioInputType type = AudioInputTypeMain) = 0;

		/// <summary>
		/// �������룬 �ͷ����б����� (��4��)
		/// </summary>
		virtual void finishEncoder() = 0;

		/// <summary>
		/// �ͷ�������Դ (��5��)
		/// </summary>
		virtual void release() = 0;
	};
}

