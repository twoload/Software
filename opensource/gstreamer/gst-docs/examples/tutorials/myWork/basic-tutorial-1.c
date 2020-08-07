#include <gst/gst.h>

int main(int argc, char* argv[])
{
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;

    gst_init ( &argc, &argv);

    pipeline = 
        gst_parse_launch
        ("playbin uri=https://https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm", NULL);
    // source, sink
    // The set of all the interconnected elements is called a "pipeline".
    // gst_parse_launch : easy version pipeline

    // playbin: single element called playgin <-- gst_parse_launch
    
    gst_element_set_state (pipeline, GST_STATE_PLAYING );
    // state: playback will start if you set the pipeline to the PLAYING state

    bus = gst_element_get_bus (pipeline);
    // retrieves the pipeline's bus



    msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);
    // block until ERROR, EOS
    // wait until an error occurs or the end of the stream is found

    if (msg != NULL)
        gst_message_unref (msg);
    gst_object_unref (bus);
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);
    return 0;
}
