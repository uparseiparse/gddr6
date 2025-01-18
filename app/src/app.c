// app.c
#include "gddr6.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void register_signal_handlers(void)
{
    struct sigaction sa;
    sa.sa_handler = gddr6_cleanup;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGHUP, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
}

int main(int argc, char **argv)
{
    register_signal_handlers();
    gddr6_init();
    int num_devs = gddr6_detect_compatible_gpus();

    if (num_devs == 0)
    {
        printf("No compatible GPU found.\n");
        return 1;
    }

    gddr6_memory_map();
    
    // Get single temperature reading for all devices
    int count;
    struct temperature_reading *readings = gddr6_get_temperatures(&count);
    
    if (readings == NULL) {
        printf("Failed to read temperatures.\n");
        gddr6_cleanup(1);
        return 1;
    }

    // Print temperature readings in simplified format
    for (int i = 0; i < count; i++) {
        printf("GPU%d: %u\n", i, readings[i].temperature);
    }

    // Free the readings array
    free(readings);
    
    // Clean up and exit
    gddr6_cleanup(0);
    return 0;
}
