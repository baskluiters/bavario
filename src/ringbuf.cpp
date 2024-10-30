#include "ringbuf.h"

RingBuffer::RingBuffer() : head(0) {
    for (int i = 0; i < RINGBUF_SIZE; i++) {
        buffer[i] = 0.0f;
    }
}

void RingBuffer::addSample(float sample) {
    buffer[head] = sample;
    head = (head + 1) % RINGBUF_SIZE;
}

float RingBuffer::averageOldestSamples(int numSamples) const {
    if (numSamples <= 0 || numSamples > RINGBUF_SIZE) return 0.0f;
    
    float sum = 0.0f;
    int startIdx = head;
    
    for (int i = 0; i < numSamples; i++) {
        sum += buffer[(startIdx + i) % RINGBUF_SIZE];
    }
    
    return sum / numSamples;
}

float RingBuffer::averageNewestSamples(int numSamples) const {
    if (numSamples <= 0 || numSamples > RINGBUF_SIZE) return 0.0f;
    
    float sum = 0.0f;
    int startIdx = (head - numSamples + RINGBUF_SIZE) % RINGBUF_SIZE;
    
    for (int i = 0; i < numSamples; i++) {
        sum += buffer[(startIdx + i) % RINGBUF_SIZE];
    }
    
    return sum / numSamples;
}
