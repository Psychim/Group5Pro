******************************************************************
******************************************************************
The new package of  'va_g729B_codec.zip' includes:

* Very Simple API call-functions
* Multi-channel capabillity
* Vad/CNG integration (Annex B)
* IETF bit-packing for G.729/G729A/G729B
* Bit-packing SID Frame for annexB compliant to ITU rec H.225.0
* Dynamic memory allocation for both encoder & decoder
* Compatibility with G.729, G.729A, G.729B, G.729AB 
* One Frame per Media-Sample, suitable for Telecommunication and Streaming Media
* Also suitable for VOIP: IP Softphone, IP VideoPhone etc.
* Most common DSP implementation for embedded systems.

For additional information on:
Linux platform,
Multi-instance 
ACM plug-in versions
or general inquiries contact: karinel@voiceage.com

******************************************************************
******************************************************************
Sample code from the demo program (encoding a process)

// pointers to the encoder state memory (all channels)
//----------------------------------------------------------------------------
G729B_ENC_STATMEM  *encStatMemPtr[NUMBER_CHANNEL_MAX];
// dynamic allocation of memory used by all the codec channels .
//----------------------------------------------------------------------------
encStatMemPtr[currentChannel] = (G729B_ENC_STATMEM *) malloc(sizeof(G729B_ENC_STATMEM));
//Initialization of all channels in use for present communication 
//----------------------------------------------------------------------------
for (currentChannel=0; currentChannel<numChannels; currentChannel++){
		 va_g729b_init_encoder(dtx_enable, encStatMemPtr[currentChannel]);
}
//encoding process calling VoiceAge library and ouput encoded data into a file 
//-----------------------------------------------------------------------------
encLengthP1 = va_g729b_encoder( dtx_enable, speech, prm, (unsigned char *)bitstream,
		 		 		 		 		 encStatMemPtr[currentChannel] );
fwrite(payloadPtr, sizeof(unsigned char), encLengthP1, fp_out[currentChannel]);


******************************************************************

Sample code from the demo program (decoding a process)

// pointers to the decoder state memory (all channels)
//----------------------------------------------------------------------------
G729B_DEC_STATMEM		 *decStatMemPtr[NUMBER_CHANNEL_MAX];
// dynamic allocation of memory used by all the codec channels .
//----------------------------------------------------------------------------
decStatMemPtr[currentChannel] = (G729B_DEC_STATMEM *) malloc(sizeof(G729B_DEC_STATMEM));
//Initialization of all channels in use for present communication 
//----------------------------------------------------------------------------
for (currentChannel=0; currentChannel<numChannels; currentChannel++){
     va_g729b_init_decoder(decStatMemPtr[currentChannel]);
}
//decoding process calling VoiceAge library and ouput encoded data into a file 
//----------------------------------------------------------------------------
va_g729b_decoder(serial, synth_buf, encFrameBytes, badFrameIndicator, decStatMemPtr[currentChannel]);
fwrite16(synth_buf, L_FRAME, fp_out[currentChannel]);