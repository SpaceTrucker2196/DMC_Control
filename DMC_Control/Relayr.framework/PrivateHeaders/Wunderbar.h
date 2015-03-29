@import Foundation;         // Apple
@class RelayrTransmitter;   // Relayr (Public)
@class RelayrDevice;        // Relayr (Public)

@interface Wunderbar : NSObject

/*!
 *  @abstract It checks whether a transmitter contains six devices and these devices are the ones in the wunderbar.
 *  @discussion A wunderbar is composed of a Master Module (<code>RelayrTransmitter</code>) and six devices: Humidity/Temperature, Gyroscope, Light/Proimity, Microphone, Bridge, and Infrared.
 *
 *  @param transmitter <code>RelayrTransmitter</code> entity representing the Master Module.
 *	@return Boolean indicating whether the transmitter can be a representation of a Master Module or not.
 *
 *  @see RelayrTransmitter
 */
+ (BOOL)isWunderbar:(RelayrTransmitter*)transmitter;

/*!
 *  @abstract Returns a boolean indicating whether a device is a wunderbar device supported model or not.
 *
 *  @param device <code>RelayrDevice</code> being tested.
 *
 *  @see RelayrDevice
 */
+ (BOOL)isDeviceSupportedByWunderbar:(RelayrDevice*)device;

/*!
 *  @abstract Returns the gyroscope device.
 *
 *  @param transmitter <code>RelayrTransmitter</code> entity representing the Master Module.
 *	@return <code>RelayrDevice</code> representing the gyroscope device.
 *
 *  @see RelayrTransmitter
 *  @see RelayrDevice
 */
+ (RelayrDevice*)gyroscopeDeviceFromWunderbar:(RelayrTransmitter*)transmitter;

/*!
 *  @abstract Returns the light and proximity device.
 *
 *  @param transmitter <code>RelayrTransmitter</code> entity representing the Master Module.
 *	@return <code>RelayrDevice</code> representing the light and proximity device.
 *
 *  @see RelayrTransmitter
 *  @see RelayrDevice
 */
+ (RelayrDevice*)lighProximityDeviceFromWunderbar:(RelayrTransmitter*)transmitter;

/*!
 *  @abstract Returns the microphone device.
 *
 *  @param transmitter <code>RelayrTransmitter</code> entity representing the Master Module.
 *	@return <code>RelayrDevice</code> representing the microphone device.
 *
 *  @see RelayrTransmitter
 *  @see RelayrDevice
 */
+ (RelayrDevice*)microphoneDeviceFromWunderbar:(RelayrTransmitter*)transmitter;

/*!
 *  @abstract Returns the humidity and temperature device.
 *
 *  @param transmitter <code>RelayrTransmitter</code> entity representing the Master Module.
 *	@return <code>RelayrDevice</code> representing the humdity and temperature device.
 *
 *  @see RelayrTransmitter
 *  @see RelayrDevice
 */
+ (RelayrDevice*)humidityTemperatureDeviceFromWunderbar:(RelayrTransmitter*)transmitter;

/*!
 *  @abstract Returns the bridge device.
 *
 *  @param transmitter <code>RelayrTransmitter</code> entity representing the Master Module.
 *	@return <code>RelayrDevice</code> representing the bridge device.
 *
 *  @see RelayrTransmitter
 *  @see RelayrDevice
 */
+ (RelayrDevice*)bridgeDeviceFromWunderbar:(RelayrTransmitter*)transmitter;

/*!
 *  @abstract Returns the infrared device.
 *
 *  @param transmitter <code>RelayrTransmitter</code> entity representing the Master Module.
 *	@return <code>RelayrDevice</code> representing the infrared device.
 *
 *  @see RelayrTransmitter
 *  @see RelayrDevice
 */
+ (RelayrDevice*)infraredDeviceFromWunderbar:(RelayrTransmitter*)transmitter;

/*!
 *  @abstract Returns the BLE advertisement local name for a specific Wunderbar device/sensor.
 *
 *  @param device The targeted Wunderbar device.
 *	@return String with the BLE advertisement local name.
 */
+ (NSString*)advertisementLocalNameForWunderbarDevice:(RelayrDevice*)device;

@end
