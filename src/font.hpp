/*******************************************************
* Copyright (c) 2015-2019, ArrayFire
* All rights reserved.
*
* This file is distributed under 3-clause BSD license.
* The complete license agreement can be obtained at:
* http://arrayfire.com/licenses/BSD-3-Clause
********************************************************/

#pragma once

#include <common.hpp>
#include <vector>

namespace internal
{

class _Font {
    private:
        /* class constants */
        static const int START_CHAR = 32;
        static const int END_CHAR = 127;
        static const int NUM_CHARS = 95;

        /* attributes */
        bool mIsFontLoaded;
        std::string mTTFfile;
        std::vector<float> mVertexData;
        int mWidth;
        int mHeight;
        GLuint mVAO;
        GLuint mVBO;
        GLuint mProgram;
        GLuint mSampler;

        GLuint mCharTextures[NUM_CHARS];
        int mAdvX[NUM_CHARS], mAdvY[NUM_CHARS];
        int mBearingX[NUM_CHARS], mBearingY[NUM_CHARS];
        int mCharWidth[NUM_CHARS], mCharHeight[NUM_CHARS];
        int mLoadedPixelSize, mNewLine;

        /* helper function to extract glyph of
        * ASCII character pointed by pIndex*/
        void extractGlyph(int pIndex);

        /* helper to destroy GL objects created for
        * given font face and size if required */
        void destroyGLResources();

    public:
        _Font();
        ~_Font();

        //FIXME copy constructor and assignment operators need
        // to be dealt with properly

        void loadFont(const char* const pFile, int pFontSize);
        void loadSystemFont(const char* const pName, int pFontSize);

        void setOthro2D(int pWidth, int pHeight);

        void render(const float pPos[2], const float pColor[4], const char* pText, int pFontSize = -1, bool pIsVertical = false);
};

}