#include <iostream>
#include "Test.h"
#include <microhttpd.h>
#include <string.h>

#define PORT 9080

int answer_to_connection(void *cls, struct MHD_Connection *connection,
                         const char *url,
                         const char *method, const char *version,
                         const char *upload_data,
                         size_t *upload_data_size, void **con_cls)
{
    const char *page = "<html><body>Hello, browser!</body></html>";
    struct MHD_Response *response;
    int ret;

    response = MHD_create_response_from_buffer(strlen(page),
                                               (void *)page, MHD_RESPMEM_PERSISTENT);
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);

    return ret;
}

int main(int argc, char **argv)
{
    struct MHD_Daemon *daemon;
    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY|MHD_USE_DEBUG, PORT, NULL, NULL,
                              &answer_to_connection, NULL, MHD_OPTION_END);
    if (nullptr == daemon)
        return 1;
    printf("running http://localhost:%d/\n", PORT);
    getchar();

    MHD_stop_daemon(daemon);
    return 0;
}