/* ***********************************************************
 * This file was automatically generated on 2016-02-10.      *
 *                                                           *
 * C/C++ Bindings Version 2.1.10                             *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#define IPCON_EXPOSE_INTERNALS

#include "bricklet_piezo_speaker.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif



typedef void (*BeepFinishedCallbackFunction)(void *);

typedef void (*MorseCodeFinishedCallbackFunction)(void *);

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(push)
	#pragma pack(1)
	#define ATTRIBUTE_PACKED
#elif defined __GNUC__
	#ifdef _WIN32
		// workaround struct packing bug in GCC 4.7 on Windows
		// http://gcc.gnu.org/bugzilla/show_bug.cgi?id=52991
		#define ATTRIBUTE_PACKED __attribute__((gcc_struct, packed))
	#else
		#define ATTRIBUTE_PACKED __attribute__((packed))
	#endif
#else
	#error unknown compiler, do not know how to enable struct packing
#endif

typedef struct {
	PacketHeader header;
	uint32_t duration;
	uint16_t frequency;
} ATTRIBUTE_PACKED Beep_;

typedef struct {
	PacketHeader header;
	char morse[60];
	uint16_t frequency;
} ATTRIBUTE_PACKED MorseCode_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED Calibrate_;

typedef struct {
	PacketHeader header;
	bool calibration;
} ATTRIBUTE_PACKED CalibrateResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED BeepFinishedCallback_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED MorseCodeFinishedCallback_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetIdentity_;

typedef struct {
	PacketHeader header;
	char uid[8];
	char connected_uid[8];
	char position;
	uint8_t hardware_version[3];
	uint8_t firmware_version[3];
	uint16_t device_identifier;
} ATTRIBUTE_PACKED GetIdentityResponse_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

static void piezo_speaker_callback_wrapper_beep_finished(DevicePrivate *device_p, Packet *packet) {
	BeepFinishedCallbackFunction callback_function;
	void *user_data = device_p->registered_callback_user_data[PIEZO_SPEAKER_CALLBACK_BEEP_FINISHED];
	(void)packet;
	*(void **)(&callback_function) = device_p->registered_callbacks[PIEZO_SPEAKER_CALLBACK_BEEP_FINISHED];

	if (callback_function == NULL) {
		return;
	}

	callback_function(user_data);
}

static void piezo_speaker_callback_wrapper_morse_code_finished(DevicePrivate *device_p, Packet *packet) {
	MorseCodeFinishedCallbackFunction callback_function;
	void *user_data = device_p->registered_callback_user_data[PIEZO_SPEAKER_CALLBACK_MORSE_CODE_FINISHED];
	(void)packet;
	*(void **)(&callback_function) = device_p->registered_callbacks[PIEZO_SPEAKER_CALLBACK_MORSE_CODE_FINISHED];

	if (callback_function == NULL) {
		return;
	}

	callback_function(user_data);
}

void piezo_speaker_create(PiezoSpeaker *piezo_speaker, const char *uid, IPConnection *ipcon) {
	DevicePrivate *device_p;

	device_create(piezo_speaker, uid, ipcon->p, 2, 0, 0);

	device_p = piezo_speaker->p;

	device_p->response_expected[PIEZO_SPEAKER_FUNCTION_BEEP] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[PIEZO_SPEAKER_FUNCTION_MORSE_CODE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[PIEZO_SPEAKER_FUNCTION_CALIBRATE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[PIEZO_SPEAKER_CALLBACK_BEEP_FINISHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	device_p->response_expected[PIEZO_SPEAKER_CALLBACK_MORSE_CODE_FINISHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	device_p->response_expected[PIEZO_SPEAKER_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	device_p->callback_wrappers[PIEZO_SPEAKER_CALLBACK_BEEP_FINISHED] = piezo_speaker_callback_wrapper_beep_finished;
	device_p->callback_wrappers[PIEZO_SPEAKER_CALLBACK_MORSE_CODE_FINISHED] = piezo_speaker_callback_wrapper_morse_code_finished;
}

void piezo_speaker_destroy(PiezoSpeaker *piezo_speaker) {
	device_release(piezo_speaker->p);
}

int piezo_speaker_get_response_expected(PiezoSpeaker *piezo_speaker, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(piezo_speaker->p, function_id, ret_response_expected);
}

int piezo_speaker_set_response_expected(PiezoSpeaker *piezo_speaker, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(piezo_speaker->p, function_id, response_expected);
}

int piezo_speaker_set_response_expected_all(PiezoSpeaker *piezo_speaker, bool response_expected) {
	return device_set_response_expected_all(piezo_speaker->p, response_expected);
}

void piezo_speaker_register_callback(PiezoSpeaker *piezo_speaker, uint8_t id, void *callback, void *user_data) {
	device_register_callback(piezo_speaker->p, id, callback, user_data);
}

int piezo_speaker_get_api_version(PiezoSpeaker *piezo_speaker, uint8_t ret_api_version[3]) {
	return device_get_api_version(piezo_speaker->p, ret_api_version);
}

int piezo_speaker_beep(PiezoSpeaker *piezo_speaker, uint32_t duration, uint16_t frequency) {
	DevicePrivate *device_p = piezo_speaker->p;
	Beep_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), PIEZO_SPEAKER_FUNCTION_BEEP, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.duration = leconvert_uint32_to(duration);
	request.frequency = leconvert_uint16_to(frequency);

	ret = device_send_request(device_p, (Packet *)&request, NULL);


	return ret;
}

int piezo_speaker_morse_code(PiezoSpeaker *piezo_speaker, const char morse[60], uint16_t frequency) {
	DevicePrivate *device_p = piezo_speaker->p;
	MorseCode_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), PIEZO_SPEAKER_FUNCTION_MORSE_CODE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	strncpy(request.morse, morse, 60);

	request.frequency = leconvert_uint16_to(frequency);

	ret = device_send_request(device_p, (Packet *)&request, NULL);


	return ret;
}

int piezo_speaker_calibrate(PiezoSpeaker *piezo_speaker, bool *ret_calibration) {
	DevicePrivate *device_p = piezo_speaker->p;
	Calibrate_ request;
	CalibrateResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), PIEZO_SPEAKER_FUNCTION_CALIBRATE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_calibration = response.calibration;



	return ret;
}

int piezo_speaker_get_identity(PiezoSpeaker *piezo_speaker, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	DevicePrivate *device_p = piezo_speaker->p;
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), PIEZO_SPEAKER_FUNCTION_GET_IDENTITY, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	strncpy(ret_uid, response.uid, 8);
	strncpy(ret_connected_uid, response.connected_uid, 8);
	*ret_position = response.position;
	memcpy(ret_hardware_version, response.hardware_version, 3 * sizeof(uint8_t));
	memcpy(ret_firmware_version, response.firmware_version, 3 * sizeof(uint8_t));
	*ret_device_identifier = leconvert_uint16_from(response.device_identifier);



	return ret;
}

#ifdef __cplusplus
}
#endif
