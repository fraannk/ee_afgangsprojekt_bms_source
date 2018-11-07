/*
 * The Clear BSD License
 * Copyright (c) 2017, NXP Semiconductors, Inc.
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __ROM_API_H_
#define __ROM_API_H_

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.rom_api"
#endif

// Power APIs
typedef struct _PWRD
{
    void (*set_pll)(unsigned int cmd[], unsigned int resp[]);
    void (*set_power)(unsigned int cmd[], unsigned int resp[]);
    void (*set_fro_frequency)(unsigned frequency);
    void (*power_mode_configure)(unsigned int power_mode, unsigned int peripheral_ctrl);
    void (*set_aclkgate)(unsigned aclkgate);
    unsigned (*get_aclkgate)(void);
} PWRD_API_T;

// Integer divide API routines
typedef struct
{
    int quot; // Quotient
    int rem;  // Remainder
} IDIV_RETURN_T;

typedef struct
{
    unsigned quot; // Quotient
    unsigned rem;  // Reminder
} UIDIV_RETURN_T;

typedef struct
{
    int (*sidiv)(int numerator, int denominator);                         // Signed integer division
    unsigned (*uidiv)(unsigned numerator, unsigned denominator);          // Unsigned integer division
    IDIV_RETURN_T (*sidivmod)(int numerator, int denominator);            // Signed integer division with remainder
    UIDIV_RETURN_T (*uidivmod)(unsigned numerator, unsigned denominator); // Unsigned integer division with remainder
} ROM_DIV_API_T;

// The master structure that defines the table of all ROM APIs on the device (a.k.a ROM Driver table)
typedef struct _ROM_API
{
    const unsigned int reserved3[3]; // Offsets 0, 4, 8
    const PWRD_API_T *pPWRD;         // Offset 0xC. Power APIs function table base address
    const ROM_DIV_API_T *divApiBase; // Offset 0x10. Integer division routines function table base address
    const unsigned int reserved7[7]; // Offsets 0x14 - 0x2C
} LPC_ROM_API_T;

#define ROM_DRIVER_BASE (0x0F001FF8UL)

// Define a pointer to the master table
#define LPC_ROM_API (*(LPC_ROM_API_T **)ROM_DRIVER_BASE)

// Use like this:
// ROM_DIV_API_T const *pROMDiv = LPC_ROM_API->divApiBase;             // Create and initialize a pointer to the DIVIDE
// functions table
// int32_t result;                                                     // Declare an int variable
// result = pROMDiv->sidiv(-99, 6);                                    // Call the sidiv routine, result now contains
// -99/6 = -16
// ROM_DIV_API_T const *pPwr = LPC_ROM_API->pPWRD;                     // Create and initialize a pointer to the power
// API functions table
// pPwr->set_power((uint32_t *)&cmd_table, (uint32_t *)&result_table); // Call the set_power routine

// Alternate form
#define LPC_PWRD_API ((PWRD_API_T *)((*(LPC_ROM_API_T **)(ROM_DRIVER_BASE))->pPWRD))
#define LPC_DIVD_API ((ROM_DIV_API_T *)((*(LPC_ROM_API_T **)(ROM_DRIVER_BASE))->divApiBase))

// Use like this:
// LPC_PWRD_API->set_power((uint32_t *)&cmd_table, (uint32_t *)&result_table); // Call the set_power routine

#endif // rom_api.h
