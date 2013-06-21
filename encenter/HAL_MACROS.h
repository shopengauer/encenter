/*
 * HAL_MACROS.h
 *
 *  Created on: 21.06.2013
 *      Author: V.Pavlov
 */

#ifndef HAL_MACROS_H_
#define HAL_MACROS_H_

/*
 *  This macro is for use by other macros to form a fully valid C statement.
 */
#define st(x)      do { x } while (__LINE__ == -1)

#endif /* HAL_MACROS_H */

