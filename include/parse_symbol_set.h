#ifndef PARSE_SYMBOL_SET_H_
#define PARSE_SYMBOL_SET_H_

/* 
 * Copyright (c) 2016, University of Virginia
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the University of Virginia nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE UNIVERSITY OF VIRGINIA BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * This software was originally developed by Jack Wadden (jackwadden@gmail.com). 
 * A list of all contributors is maintained at https://github.com/jackwadden/VASim.
 * 
 * If you use VASim in your project, please use the following citation:
 * Wadden, J. and Skadron, K. "VASim: An Open Source Simulation and Analysis
 * Platform for Finite Automata Applications and Architecture Research." GitHub
 * repository, https://github.com/jackwadden/VASim. University of Virginia, 2016.
 */

/*
 * Modified by Kevin Angstadt <angstadt@virginia.edu> for use with HyperScan
 */

#ifdef __cplusplus

#include "util/charreach.h"

namespace ue2 {
    void parseSymbolSet(CharReach &column, std::string symbol_set);
}

#endif

#endif