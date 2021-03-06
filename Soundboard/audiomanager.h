#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <QFile>
#include <QAudioOutput>
#include <QAudioInput>
#include <QAudioRecorder>
#include <vector>

class AudioManager : public QObject
{
    Q_OBJECT

public:
    AudioManager();
    ~AudioManager();

    bool isPlaying();
    void setRecordingSoundboard(bool recording);
    bool isRecordingSoundboard();
    void setRecordingMic(bool recording);
    bool isRecordingMic();

    QFile* getTrack();
    void play();
    void pause();
    void loop();

    void addSound(QFile *file);
    void playSound(int index);

private:
    QAudioFormat format;
    QAudioOutput *audioOutput;
    QAudioInput *audioInput;
//    QAudioRecorder *audioRecorder;

    bool playing;
    bool recordingSoundboard;
    bool recordingMic;

    QFile *readTrack;
    QFile *writeTrack;

    std::vector<QFile*> sounds;

private slots:
    void audioOutputStateChanged(QAudio::State);
};

#endif // AUDIOMANAGER_H
