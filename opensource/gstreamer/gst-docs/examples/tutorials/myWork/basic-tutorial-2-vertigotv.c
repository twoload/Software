#include <gst/gst.h>

int main(int argc, char* argv[])
{
    GstElement *pipeline, *source, *vertigotv, *videoconvert, *sink; // source, sink
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret; // new

    gst_init ( &argc, &argv);

    source = gst_element_factory_make ("videotestsrc", "source");
    sink = gst_element_factory_make ("autovideosink", "sink");
    vertigotv = gst_element_factory_make ("vertigotv", "vertigotv");
    videoconvert = gst_element_factory_make ("videoconvert", "videoconvert");

    pipeline = gst_pipeline_new ("test-pipeline");

    if(!pipeline || !source || !sink ){
        g_printerr ("Not all elements could be created.\n");
        return -1;
    }

    gst_bin_add_many (GST_BIN (pipeline), source, videoconvert, sink, NULL); // add_many
    if (gst_element_link_many (source, videoconvert, sink, NULL) != TRUE ){ // link_many
        g_printerr ("Element could not be linked.\n");
        gst_object_unref (pipeline);
        return -1;
    }

    g_object_set (source, "pattern", 0, NULL);
    
    ret = gst_element_set_state (pipeline, GST_STATE_PLAYING );
    if( ret == GST_STATE_CHANGE_FAILURE){
        g_printerr ("Unable to set the pipeline to the playing state.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    bus = gst_element_get_bus (pipeline);
    msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);
    // block until ERROR, EOS
    // wait until an error occurs or the end of the stream is found

    if (msg != NULL){
        GError *err;
        gchar *debug_info;

        switch (GST_MESSAGE_TYPE (msg)){
            case GST_MESSAGE_ERROR:
                gst_message_parse_error( msg, &err, &debug_info);
                g_printerr("Error received from element %s; %s\n", GST_OBJECT_NAME(msg->src), err->message);
                g_printerr("Debugging information: %s\n", debug_info? debug_info:"none");
                g_clear_error (&err);
                g_free (debug_info);
                break;
            case GST_MESSAGE_EOS:
                g_print("End-Of-Stream reached.\n");
                break;
            default:
                g_printerr("Unexpected message received.\n");
                break;
        }
        gst_message_unref (msg);
    }
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    return 0;
}
