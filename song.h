#ifndef LSDJ_SONG_H
#define LSDJ_SONG_H

#include "error.h"
#include "instrument.h"
#include "vio.h"

#ifdef __cplusplus
extern "C" {
#endif
    
static const unsigned int SONG_DECOMPRESSED_SIZE = 0x8000;
static const unsigned int SEQUENCE_COUNT = 4;
static const unsigned int SEQUENCE_LENGTH = 256;
static const unsigned int PHRASE_COUNT = 0xFF;
static const unsigned int PHRASE_LENGTH = 16;
static const unsigned int BOOKMARK_COUNT = 64;
static const unsigned int INSTRUMENT_COUNT = 64;

//! An LSDJ song
typedef struct
{    
    //! The sequences of chains in the song
    unsigned char sequences[SEQUENCE_LENGTH][SEQUENCE_COUNT];
    
    //! The chains in the song
    
    //! The prases in the song
    unsigned char phrases[PHRASE_LENGTH][PHRASE_COUNT];
    
    //! Bookmarks
    unsigned char bookmarks[BOOKMARK_COUNT];
    
    //! The grooves in the song
    unsigned char grooves[512];
    
    //! Instruments of the song
    instrument_t instruments[INSTRUMENT_COUNT];
    
    unsigned char bank0[0x2000];
    unsigned char bank1[0x2000];
    unsigned char bank2[0x2000];
    unsigned char bank3[0x2000];
    
} lsdj_song_t;

void lsdj_read_song(lsdj_vio_read_t read, lsdj_vio_tell_t tell, lsdj_vio_seek_t seek, void* user_data, lsdj_song_t* song, lsdj_error_t** error);
void lsdj_read_song_from_memory(const unsigned char* data, size_t size, lsdj_song_t* song, lsdj_error_t** error);
    
//! Write an LSDJ song to memory
void lsdj_write_song(const lsdj_song_t* song, lsdj_vio_write_t write, void* user_data, lsdj_error_t** error);
void lsdj_write_song_to_memory(const lsdj_song_t* song, unsigned char* data, size_t size, lsdj_error_t** error);

#ifdef __cplusplus
}
#endif

#endif
