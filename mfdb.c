#include "general.h"


/*==================================================================================*
 * int16 init_mfdb:																	*
 *				fit a MFDB with the parameters suppplied.							*
 *----------------------------------------------------------------------------------*
 * input:																			*
 * 		bm		-> 	The MFDB to fit.												*
 * 		width	-> 	Image's width. 													*
 * 		height	-> 	Image's height.										 			*
 * 		planes	->	Screen planes or 1 if the image is monochrome.					*
 *----------------------------------------------------------------------------------*
 * return:																			*	
 *		'1' if ok else '0'.															*
 *==================================================================================*/
int16 init_mfdb( MFDB *bm, int16 width, int16 height, int16 planes)
{
	uint32 length;

	bm->fd_w 		= width;
	bm->fd_h 		= height;
	bm->fd_wdwidth	= ( width >> 4) + (( width % 16) != 0);
	bm->fd_stand 	= 0;
	bm->fd_nplanes 	= planes;
	bm->fd_r1      	= 0;
	bm->fd_r2      	= 0;
	bm->fd_r3	  	= 0;

	length			= (( (( uint32)bm->fd_wdwidth << 1 ) * ( uint32)bm->fd_nplanes) * ( uint32)bm->fd_h) + 256L;
	bm->fd_addr 	= gmalloc( length);

	if( bm->fd_addr)
		return( 1);
	
	bm->fd_addr = NULL;

	return ( 0);
}


/*==================================================================================*
 * int16 delete_mfdb:																*
 *		free a MFDB.																*
 *----------------------------------------------------------------------------------*
 * input:																			*
 * 		bm		-> 	pointer to the MFDB to free.									*
 *----------------------------------------------------------------------------------*
 * return:																			*	
 *		--																			*
 *==================================================================================*/
void delete_mfdb( MFDB *bm)
{
	if ( bm->fd_addr == NULL)
		return;

	gfree( bm->fd_addr);
	bm->fd_addr = NULL;
}

