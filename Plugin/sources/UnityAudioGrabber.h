

#ifndef __UnityAudioGrabber__
#define __UnityAudioGrabber__

#include "CustomAudioGrabber.h"
#include <list>

namespace mray
{
namespace video
{

class UnityAudioGrabber :public IAudioGrabber
{
protected:
	int _channels;
	int _samplingRate;
	int _bufferLength;
	bool _started;
	std::list<float*> _samples;
	std::list<float*> _graveyard;
public:
	UnityAudioGrabber();
	virtual ~UnityAudioGrabber();

	void Init(int bufferLength, int channels, int samplingrate);

	void AddFrame(float* data);

	virtual bool Start();
	virtual void Pause();
	virtual void Close();
	virtual void Resume(){};
	virtual void Restart(){};
	virtual bool IsStarted();

	virtual uint GetSamplingRate();
	virtual uint GetChannelsCount();


	virtual bool GrabFrame();
	virtual uchar* GetAudioFrame();
	virtual uint GetAudioFrameSize();

	virtual void SetVolume(float vol);
};

}
}

#endif
