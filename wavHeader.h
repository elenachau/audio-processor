//
// Created by trentr on 4/16/22.
//

#ifndef PROJECT_WAV_HEADER_H
#define PROJECT_WAV_HEADER_H

typedef struct wavHeader {
    // RIFF Header
    char riff_header[4]; // Contains "RIFF"
    int wav_size; // Size of the wav portion of the file, which follows the first 8 bytes. File size - 8
    char wave_header[4]; // Contains "WAVE"

    // Format Header
    char fmt_header[4]; // Contains "fmt " (includes trailing space)
    int fmt_chunk_size; // Should be 16 for PCM
    short audio_format; // Should be 1 for PCM. 3 for IEEE Float
    short num_channels; //Says whether it is mono or stereo
    int sample_rate;
    int byte_rate; // Number of bytes per second. sample_rate * num_channels * Bytes Per Sample
    short sample_alignment; // num_channels * Bytes Per Sample, 2=16-bit mono, 4 = 16-bit stereo
    short bit_depth; // Number of bits per sample, aka 8-bit or 16-bit

    // Data
    char data_header[4]; // Contains "data"
    int data_bytes; // Number of bytes in data. Number of samples * num_channels * sample byte size
    // uint8_t bytes[]; // Remainder of wave file is bytes
} wav_hdr;

#endif //PROJECT_WAV_HEADER_H
