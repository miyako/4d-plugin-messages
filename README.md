# 4d-pluin-messages
Connect to the Messages (com.apple.iChat) app. 

##Platform

| carbon | cocoa | win32 | win64 |
|:------:|:-----:|:---------:|:---------:|
|🆗|🆗|🚫|🚫|

##Examples

```
  //note: to prevent annoying the user by launch Messages,
  //the plugin will only run if the app is not running
ARRAY TEXT($id;0)
ARRAY TEXT($name;0)
ARRAY BOOLEAN($enabled;0)
ARRAY LONGINT($connectionStatus;0)
ARRAY LONGINT($myStatus;0)
ARRAY TEXT($statusMessage;0)
ARRAY LONGINT($serviceType;0)

  //get list of services
MESSAGE SERVICE LIST (\
$id;\
$name;\
$enabled;\
$connectionStatus;\
$myStatus;\
$statusMessage;\
$serviceType)

  //information about a service
$connection:=$connectionStatus{Size of array($connectionStatus)}
Case of 
: ($connection=Messages Connected)
: ($connection=Messages Connecting)
: ($connection=Messages Disconnected)
: ($connection=Messages Disconnecting)
End case 

$me:=$myStatus{Size of array($myStatus)}
Case of 
: ($me=Messages My Account Available)
: ($me=Messages My Account Away)
: ($me=Messages My Account Invisible)
: ($me=Messages My Account Offline)
End case 

$type:=$serviceType{Size of array($serviceType)}
Case of 
: ($type=Messages Service AIM)
: ($type=Messages Service Bonjour)
: ($type=Messages Service IMessage)
: ($type=Messages Service Jabber)
End case 

$imessage:=Find in array($serviceType;Messages Service IMessage)
If ($imessage#-1)
$service:=$id{$imessage}
Send ($service;"keisuke miyako";"message")
End if 
```

* Send

```
$service:=$1

  //MESSAGE SERVICE LOGOUT ($service)
  //MESSAGE SERVICE LOGIN ($service)

ARRAY TEXT($id;0)
ARRAY TEXT($name;0)
ARRAY TEXT($handle;0)
ARRAY LONGINT($status;0)
ARRAY TEXT($statusMessage;0)
ARRAY LONGINT($idleTime;0)
ARRAY PICTURE($image;0)

MESSAGE SERVICE BUDDY LIST ($service;\
$id;\
$name;\
$handle;\
$status;\
$statusMessage;\
$idleTime;\
$image)

$find:=Find in array($name;$2)

If ($find#-1)
$buddy:=$id{$find}
$buddyname:=$name{$find}
MESSAGE SEND ($buddy;$3)
End if 
```
