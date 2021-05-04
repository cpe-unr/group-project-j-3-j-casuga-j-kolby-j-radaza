#ifndef WAVEHEADER_H
#define WAVEHEADER_H
/**
 * This is the wave header struct that holds the data of the file headers
 * Stolen from Keith Lancaster
 */
struct waveHeader {
	char riff_header[4];
	int wav_size;
	char wave_header[4];

	char fmt_header[4];
	int fmt_chunk_size;
	short audio_format;
	short num_channels;
	int sample_rate;
	int byte_rate;
	short sample_alignment;
	short bit_depth;

	char data_header[4];
	int data_bytes;
};

/**
 * This is the struct for holding the metadata
 * Created by James Kolby
 */
struct metadata {
	char inam[4];
	char iart[4];
	char iprd[4];
	char ignr[4];
	char icrd[4];
	char itrk[4];
	char icmt[4];
};

#endif //WAVEHEADER_H

