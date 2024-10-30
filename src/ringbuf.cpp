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

float RingBuffer::calculateAverage(int startIdx, int numSamples) const {
    if (numSamples <= 0 || numSamples > RINGBUF_SIZE) return 0.0f;
    
    float sum = 0.0f;
    for (int i = 0; i < numSamples; i++) {
        sum += buffer[(startIdx + i) % RINGBUF_SIZE];
    }
    return sum / numSamples;
}

float RingBuffer::averageOldestSamples(int numSamples) const {
    return calculateAverage(head, numSamples);
}

float RingBuffer::averageNewestSamples(int numSamples) const {
    return calculateAverage((head - numSamples + RINGBUF_SIZE) % RINGBUF_SIZE, numSamples);
}
