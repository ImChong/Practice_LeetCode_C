/*
 * @FilePath     : \Practice_LeetCode_C\F01_Common_Functions\inc\commonString.h
 * @Author       : Chong Liu
 * @CreateDate   : 2023-10-24 00:56:41
 * @LastEditors  : Chong Liu
 * @LastEditTime : 2024-01-19 07:59:15
 * =================================================================================
 * Copyright (c) 2023 by Chong Liu, All Rights Reserved.
 * =================================================================================
 * @Description  : Common string header file
 */
#ifndef F01_COMMON_FUNCTIONS_INC_COMMON_STRING_H_
#define F01_COMMON_FUNCTIONS_INC_COMMON_STRING_H_

/**********************************************************************************/
/*                                                                                */
/*                                UTILITY FUNCTIONS                               */
/*                                                                                */
/**********************************************************************************/
int Char_Swap(char *a, char *b);                            /* Swap two characters */
int String_Reverse(char *s, int left_index, int right_index); /* Reverse string */

/**********************************************************************************/
/*                                                                                */
/*                                HELPER FUNCTIONS                                */
/*                                                                                */
/**********************************************************************************/
int String_Print(char *s); /* Print string */
int String_Free(char **s); /* Release string */

/**********************************************************************************/
/*                                                                                */
/*                                  TEST FUNCTION                                 */
/*                                                                                */
/**********************************************************************************/
int Validate_String(char testNum, char *expect, char *actual); /* Validate string */

#endif /* F01_COMMON_FUNCTIONS_INC_COMMON_STRING_H_ */
