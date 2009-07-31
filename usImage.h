/*
 *  usImage.h
 *  PHD Guiding
 *
 *  Created by Craig Stark on 9/20/08.
 *  Copyright (c) 2006, 2007, 2008, 2009 Craig Stark.
 *  All rights reserved.
 *
 *  This source code is distrubted under the following "BSD" license
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *    Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *    Neither the name of Craig Stark, Stark Labs nor the names of its contributors may be used to endorse or promote products derived from this
 *     software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef USIMAGECLASS
#define USIMAGECLASS
class usImage {
public:
	unsigned short		*ImageData;		// Pointer to raw data
	wxSize				Size;				// Dimensions of image
	wxPoint				Origin;			// Data origin - if not 0,0, subframed
	int					NPixels;
	int					Min;
	int					Max;
	int					Mean;
	//	int					Binsize;
	bool					Init(int xsize, int ysize);
	void					CalcStats();
	bool					CopyToImage(wxImage **img, int min, int max, double power);
	bool					BinnedCopyToImage(wxImage **img, int min, int max, double power); // Does 2x2 bin during copy
	bool					Clean();
	usImage() { Min=Max=Mean= 0; NPixels = 0; ImageData = NULL;}
	~usImage() {delete[] ImageData; }
};

#endif
