/*
 * File: coder_profile_timer.h
 *
 * Code generated for instrumentation.
 *
 */

#include "rtwtypes.h"

/* Called before starting a profiled section of code */
void profileStart(uint32_T);

/* Called on finishing a profiled section of code */
void profileEnd(uint32_T);

/* Pause the timer while running code associated with storing and uploading the data. */
void xilProfilingTimerFreeze(void);

/* Restart the timer after a pause */
void xilProfilingTimerUnFreeze(void);

/* Code instrumentation method(s) for model SFS */
void profileStart_SFS(uint32_T sectionId);
void profileEnd_SFS(uint32_T sectionId);
