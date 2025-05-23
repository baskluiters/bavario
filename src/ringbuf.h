#ifndef RINGBUF_H_
#define RINGBUF_H_

#define RINGBUF_SIZE    20

class RingBuffer {
private:
    int head;
    float buffer[RINGBUF_SIZE];
    float calculateAverage(int startIdx, int numSamples) const;

public:
    RingBuffer();  // Constructor
    void addSample(float sample);
    float averageOldestSamples(int numSamples) const;
    float averageNewestSamples(int numSamples) const;
};

#endif
