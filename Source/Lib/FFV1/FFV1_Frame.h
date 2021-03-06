/*  Copyright (c) MediaArea.net SARL & AV Preservation by reto.ch.
 *
 *  Use of this source code is governed by a BSD-style license that can
 *  be found in the License.html file in the root of the source tree.
 */

//---------------------------------------------------------------------------
#ifndef FFV1_FrameH
#define FFV1_FrameH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "Lib/FFV1/FFV1_Slice.h"
//---------------------------------------------------------------------------

//***************************************************************************
// Class frame
//***************************************************************************

class ThreadPool;
class raw_frame;

class frame
{
public:
    // Constructor/Destructor
    frame();
    ~frame();

    // External metadata
    void SetWidth(uint32_t width);
    void SetHeight(uint32_t width);

    // Before - Global
    void Read_Buffer_OutOfBand(uint8_t* Buffer, size_t Buffer_Size);
    void Read_Buffer_Continue(uint8_t* Buffer, size_t Buffer_Size);

    // Decoded frame
    raw_frame*                  RawFrame;

    // Error message
    const char* ErrorMessage();

private:
    // Parameters
    parameters                  P;
    rangecoder                  E;

    // Temp
    bool                        KeyFrame_IsPresent;
    slice_struct*               Slices;
    ThreadPool*                 Pool;

    // Helpers
    void Clear();
};

//---------------------------------------------------------------------------
#endif
