#include <stdint.h>
typedef uint_least8_t u8;
typedef int_least8_t i8;
enum RngScheme{ RSur1, RSir1 };
enum OCodes { ALL_ZERO, CONST_BYTE }
/** in points to 128 bytes */
void rngTest( enum RngScheme const sch, char *buf, char *out, uint32_t *osz ){
    uint32_t const bsz = 128U;
    *osz=0U;
    switch(sch){
        case(RSur1):
	    {
			u8* b = (u8*)buf;
			u8* o = (u8*)out;
			// Get max and min with 8-byte period
			u8 cmin[8] = {0xffU,0xffU,0xffU,0xffU, 0xffU,0xffU,0xffU,0xffU};
			u8 cmax[8] = {0x00U,0x00U,0x00U,0x00U, 0x00U,0x00U,0x00U,0x00U};
	    	for(uint32_t i=0U; i<bsz; i+=8U){
				u8 c;
				for( uint32_t j=0U; j<8U; ++j){
					c = *b++; if( c < cmin[j] ) cmin[j] = c; if( c > cmax[j] ) cmax[j] = c;
				}
			}
			// Get bw for 8-byte period
			uint16_t bw[8];
			for( uint8_t i=0U; i<8U; ++i){
				bw[i] = __builtin_popcount( cmax[i]-cmin[i] );
			}
			// Get minima of bw, to help detect whether 8/4/2/1-byte period
			u8 m[4]; u8 nm=0U;
			u8 mprv = (u8)255U;
			if(                  bw[1] > bw[0] ){ m[nm++] = 0U; }
			if( bw[1] < bw[0] && bw[1] > bw[2] ){ m[nm++] = 1U; }
			if( bw[2] < bw[1] && bw[2] > bw[3] ){ m[nm++] = 2U; }
			if( bw[3] < bw[2] && bw[3] > bw[4] ){ m[nm++] = 3U; }
			if( bw[4] < bw[3] && bw[4] > bw[5] ){ m[nm++] = 4U; }
			if( bw[5] < bw[4] && bw[5] > bw[6] ){ m[nm++] = 5U; }
			if( bw[6] < bw[5] && bw[6] > bw[7] ){ m[nm++] = 6U; }
			if( bw[7] < bw[6]                  ){ m[nm++] = 7U; }

			// suppose per=8.  What bit cost?
			// suppose we encode bw[8] using 3 bits each:
			// bsz/8 ~ 128/8 = 16
			// then total bit cost c8 [,c4,c2,c1] is:
			uint16_t c8 = 8U*3U + (bsz/8U) * (bw[0]+bw[1]+bw[2]+bw[3]+bw[4]+bw[5]+bw[6]+bw[7]);

			uint16_t bw4[4];
			for( u8 i=0U; i<4U; ++i )
				bw4[i] = (bw[i]>bw[i+4]? bw[i]: bw[i+4]);	// max( bw[i], bw[i+4] )
			uint16_t c4 = 4U*3U + (bsz/4U) * (bw4[0]+bw4[1]+bw4[2]+bw4[3]);

			uint16_t bw2[2];
			bw2[0] = (bw4[0] > bw4[2]? bw4[0]: bw4[2]);
			bw2[1] = (bw4[1] > bw4[3]? bw4[1]: bw4[3]);
			uint16_t c2 = 2U*3U + (bsz/2U) * (bw2[0]+bw2[1]);

			uint16_t bw1 = (bw2[0] > bw2[1]? bw2[0]: bw2[1]);
			uint16_t c1 = 3U + (bsz/1U) * (bw1);
			// So if bit widths are same with higher period save some (few) bits
			// What's the best period?
			u8 per = 8U;
			if( c4 < c8 ) per = 4U;
			if( c2 < c4 ) per = 2U;
			if( c1 < c2 ) per = 1U;

	    }
	    break;
        case(RSir1):
	    {
	    }
	    break;
    }
}
	
