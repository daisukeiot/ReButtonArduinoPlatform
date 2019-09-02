// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. 
#include "Arduino.h"
#include "app_httpd.h"

static bool startupWebServer(void)
{
    int ret = httpd_server_start();

    return (ret == 0 ? true : false);
}

void EnableSystemWeb(int extFunctions)
{
}

void StartupSystemWeb(void)
{
    startupWebServer();

    while (true)
    {
        wait_ms(1000);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
// Provide extensibility for add extra settings
int SystemWebAddSettings(WEB_PAGE_SETTINGS *settings)
{
    if (settings == NULL)
    {
        return -1;
    }
    if (settings->name == NULL
        || settings->items == NULL
        || settings->result_fun == NULL
        || settings->item_number == 0)
    {
        return -1;
    }
    for (int i = 0; i < settings->item_number; i++)
    {
        if (settings->items[i].name == NULL
            || settings->items[i].display_name == NULL
            || settings->items[i].value_len == 0)
        {
            return -1;
        }
    }
    return app_httpd_add_settings(settings);
}