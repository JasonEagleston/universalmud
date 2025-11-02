#ifndef UNIVERSAL_MUD_YEARS
#define UNIVERSAL_MUD_YEARS
typedef struct {
	uint64_t world_start;
	// For now we assume world speed time will always be the same after it is initially set.
	// In the future, hold timestamps of each world speed time change to compensate for calculations?
} YearData;
#endif
