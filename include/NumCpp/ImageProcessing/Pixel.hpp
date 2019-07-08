/// @file
/// @author David Pilger <dpilger26@gmail.com>
/// [GitHub Repository](https://github.com/dpilger26/NumCpp)
/// @version 1.1
///
/// @section License
/// Copyright 2019 David Pilger
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this
/// software and associated documentation files(the "Software"), to deal in the Software
/// without restriction, including without limitation the rights to use, copy, modify,
/// merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
/// permit persons to whom the Software is furnished to do so, subject to the following
/// conditions :
///
/// The above copyright notice and this permission notice shall be included in all copies
/// or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
/// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
/// PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
/// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
/// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
/// @section Description
/// Holds the information for a single pixel
///

#pragma once

#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/num2str.hpp"

#include <iostream>
#include <string>

namespace nc
{
    namespace imageProcessing
    {
        //================================================================================
        // Class Description:
        ///						Holds the information for a single pixel
        template<typename dtype>
        class Pixel
        {
        public:
            //==================================Attributes================================///
            mutable int32	clusterId{ -1 };
            uint32	        row{ 0 };
            uint32	        col{ 0 };
            dtype	        intensity{ 0 };

            //=============================================================================
            // Description:
            ///              defualt constructor needed by containers
            ///
            Pixel() = default;

            //=============================================================================
            // Description:
            ///              constructor
            ///
            /// @param              inRow: pixel row
            /// @param              inCol: pixel column
            /// @param              inIntensity: pixel intensity
            ///
            Pixel(uint32 inRow, uint32 inCol, dtype inIntensity) noexcept :
                row_(inRow),
                col_(inCol),
                intensity_(inIntensity)
            {};

            //=============================================================================
            // Description:
            ///              equality operator
            ///
            /// @param
            ///              rhs
            ///
            /// @return
            ///              bool
            ///
            bool operator==(const Pixel<dtype>& rhs) const noexcept
            {
                return row_ == rhs.row_ && col_ == rhs.col_ && intensity_ == rhs.intensity_;
            }

            //=============================================================================
            // Description:
            ///              not equality operator
            ///
            /// @param
            ///              rhs
            ///
            /// @return
            ///              bool
            ///
            bool operator!=(const Pixel<dtype>& rhs) const noexcept
            {
                return !(*this == rhs);
            }

            //=============================================================================
            // Description:
            ///              less than operator for std::sort algorithm and std::set<>;
            ///              NOTE: std::sort sorts in ascending order. Since I want to sort
            ///              the centroids in descensing order, I am purposefully defining
            ///              this operator backwards!
            ///
            /// @param
            ///              rhs
            ///
            /// @return
            ///              bool
            ///
            bool operator<(const Pixel<dtype>& rhs) const noexcept
            {
                if (row_ < rhs.row_)
                {
                    return true;
                }
                else if (row_ == rhs.row_)
                {
                    if (col_ < rhs.col_)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }

            //=============================================================================
            // Description:
            ///              returns the pixel information as a string
            ///
            /// @return
            ///              std::string
            ///
            std::string str() const
            {
                std::string out = "row = " + utils::num2str(row) + " col = " + utils::num2str(col);
                out += " intensity = " + utils::num2str(intensity) + "\n";
                return out;
            }

            //============================================================================
            /// Method Description:
            ///						prints the Pixel object to the console
            ///
            void print() const
            {
                std::cout << *this;
            }

            //=============================================================================
            // Description:
            ///              osstream operator
            ///
            /// @param              inStream
            /// @param              inPixel
            /// @return
            ///              std::ostream
            ///
            friend std::ostream& operator<<(std::ostream& inStream, const Pixel<dtype>& inPixel)
            {
                inStream << inPixel.str();
                return inStream;
            }
        };
    }
}
