#include "usb.h"
#include "usb_ch9.h"
#include "usb_cdc.h"
#include "usb_config.h"

int8_t app_send_encapsulated_command(uint8_t interface, uint16_t length)
{
    return -1;
}

int16_t app_get_encapsulated_response(uint8_t interface,
                                      uint16_t length, const void **report,
                                      usb_ep0_data_stage_callback *callback,
                                      void **context)
{
    return -1;
}

int8_t app_set_comm_feature_callback(uint8_t interface,
                                     bool idle_setting,
                                     bool data_multiplexed_state)
{
    return -1;
}

int8_t app_clear_comm_feature_callback(uint8_t interface,
                                       bool idle_setting,
                                       bool data_multiplexed_state)
{
    return -1;
}

int8_t app_get_comm_feature_callback(uint8_t interface,
                                     bool *idle_setting,
                                     bool *data_multiplexed_state)
{
    return -1;
}

static struct cdc_line_coding line_coding =
{
    115200,
    CDC_CHAR_FORMAT_1_STOP_BIT,
    CDC_PARITY_NONE,
    8,
};

int8_t app_set_line_coding_callback(uint8_t interface,
                                    const struct cdc_line_coding *coding)
{
    line_coding = *coding;
    return 0;
}

int8_t app_get_line_coding_callback(uint8_t interface,
                                    struct cdc_line_coding *coding)
{
    /* This is where baud rate, data, stop, and parity bits are set. */
    *coding = line_coding;
    return 0;
}

int8_t app_set_control_line_state_callback(uint8_t interface,
                                           bool dtr, bool dts)
{
    return 0;
}

int8_t app_send_break_callback(uint8_t interface, uint16_t duration)
{
    return 0;
}

int8_t app_unknown_setup_request_callback(const struct setup_packet *setup)
{
    /* To use the CDC device class, have a handler for unknown setup
     * requests and call process_cdc_setup_request() (as shown here),
     * which will check if the setup request is CDC-related, and will
     * call the CDC application callbacks defined in usb_cdc.h. For
     * composite devices containing other device classes, make sure
     * MULTI_CLASS_DEVICE is defined in usb_config.h and call all
     * appropriate device class setup request functions here.
     */
    return process_cdc_setup_request(setup);
}

int16_t app_unknown_get_descriptor_callback(const struct setup_packet *pkt, const void **descriptor)
{
    return -1;
}