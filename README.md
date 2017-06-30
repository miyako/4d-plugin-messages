# 4d-plugin-messages
Connect to the Messages (com.apple.iChat) app. 

### Platform

| carbon | cocoa | win32 | win64 |
|:------:|:-----:|:---------:|:---------:|
|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|||

### Version

<img src="https://cloud.githubusercontent.com/assets/1725068/18940649/21945000-8645-11e6-86ed-4a0f800e5a73.png" width="32" height="32" /> <img src="https://cloud.githubusercontent.com/assets/1725068/18940648/2192ddba-8645-11e6-864d-6d5692d55717.png" width="32" height="32" />

## Examples

```
  //note: to prevent annoying the user by launching Messages,
  //the plugin will only run if the app is not running
  
OPEN URL("";"Messages")

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
$image)//always empty?

$find:=Find in array($name;$2)

If ($find#-1)
$buddy:=$id{$find}
$buddyname:=$name{$find}
MESSAGE SEND ($buddy;$3)
End if 
```

* Discussion

First. you need to decide which service to use.

On a typical Mac, you would see see ``Bonjour``, ``SMS`` and ``E:keisuke.miyako@4d.com``, for example.

Only the last 2 are probably enabled, or ``True``, with the connection status ``Messages Connected (1)``. (``MESSAGE SERVICE LIST``)

By running ``MESSAGE SERVICE BUDDY LIST`` with each type of service (SMS and E), you should see that the ID is different for the same phone number, depending on the service type.

```
"8A5D8B62-F1D5-45A1-BD68-6B6C5CB3A435:+818032404541"	//SMS
"8862431A-EFF9-41B9-A954-B1D63730A6D4:+818032404541"	//E
 ```
 
anyway, now that you know the service+phone combination, you can send using either service.

```
MESSAGE SEND ("8A5D8B62-F1D5-45A1-BD68-6B6C5CB3A435:+818032404541";"message by SMS")
MESSAGE SEND ("8862431A-EFF9-41B9-A954-B1D63730A6D4:+818032404541";"message by E")
```

