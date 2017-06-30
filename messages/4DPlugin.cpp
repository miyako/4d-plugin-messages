/* --------------------------------------------------------------------------------
 #
 #	4DPlugin.cpp
 #	source generated by 4D Plugin Wizard
 #	Project : Messages
 #	author : miyako
 #	2016/05/25
 #
 # --------------------------------------------------------------------------------*/


#include "4DPluginAPI.h"
#include "4DPlugin.h"

static MessagesApplication *Messages = [SBApplication applicationWithBundleIdentifier:@"com.apple.iChat"];

void PluginMain(PA_long32 selector, PA_PluginParameters params)
{
	try
	{
		PA_long32 pProcNum = selector;
		sLONG_PTR *pResult = (sLONG_PTR *)params->fResult;
		PackagePtr pParams = (PackagePtr)params->fParameters;

		switch(pProcNum)
		{
			case 2 :
				MESSAGE_SERVICE_BUDDY_LIST(params);
				break;
			
			default:
				CommandDispatcher(pProcNum, pResult, pParams);
				break;
		}

	}
	catch(...)
	{

	}
}

void CommandDispatcher (PA_long32 pProcNum, sLONG_PTR *pResult, PackagePtr pParams)
{
	switch(pProcNum)
	{
// --- Messages

		case 1 :
			MESSAGE_SERVICE_LIST(pResult, pParams);
			break;

		case 3 :
			MESSAGE_SERVICE_LOGIN(pResult, pParams);
			break;

		case 4 :
			MESSAGE_SERVICE_LOGOUT(pResult, pParams);
			break;

		case 5 :
			MESSAGE_SEND(pResult, pParams);
			break;

	}
}

#pragma mark -

// ----------------------------------- Messages -----------------------------------

void MESSAGE_SERVICE_LIST(sLONG_PTR *pResult, PackagePtr pParams)
{
	ARRAY_TEXT Param1;
	ARRAY_TEXT Param2;
	ARRAY_BOOLEAN Param3;
	ARRAY_LONGINT Param4;
	ARRAY_LONGINT Param5;
	ARRAY_TEXT Param6;
	ARRAY_LONGINT Param7;
	
	if((Messages) && ([Messages isRunning]))
	{
	
		SBElementArray *services = [Messages services];
		NSArray *idArray = [services arrayByApplyingSelector:@selector(id)];
		NSArray *nameArray = [services arrayByApplyingSelector:@selector(name)];
		NSArray *enabledArray = [services arrayByApplyingSelector:@selector(enabled)];
		NSArray *connectionStatusArray = [services arrayByApplyingSelector:@selector(connectionStatus)];
		NSArray *statusArray = [services arrayByApplyingSelector:@selector(status)];
		NSArray *statusMessageArray = [services arrayByApplyingSelector:@selector(statusMessage)];
		NSArray *serviceTypeArray = [services arrayByApplyingSelector:@selector(serviceType)];

		Param1.setSize(1);
		Param2.setSize(1);
		Param3.setSize(1);
		Param4.setSize(1);
		Param5.setSize(1);
		Param6.setSize(1);
		Param7.setSize(1);
		
		for(NSUInteger i = 0; i < [services count]; ++i)
		{
			Param1.appendUTF16String([idArray objectAtIndex:i]); // string
			Param2.appendUTF16String([nameArray objectAtIndex:i]); // string
			Param3.appendBooleanValue([[enabledArray objectAtIndex:i]boolValue]); // boolean
			Param6.appendUTF16String([statusMessageArray objectAtIndex:i]); // string
			
			switch ([[connectionStatusArray objectAtIndex:i]enumCodeValue])
			{
				case MessagesConnectionStatusDisconnecting:
					Param4.appendIntValue(0);
					break;
				case MessagesConnectionStatusConnected:
					Param4.appendIntValue(1);
					break;
				case MessagesConnectionStatusConnecting:
					Param4.appendIntValue(2);
					break;
				case MessagesConnectionStatusDisconnected:
					Param4.appendIntValue(3);
					break;
				default:
					Param4.appendIntValue(-1);
					break;
			}
			
			switch ([[serviceTypeArray objectAtIndex:i]enumCodeValue])
			{
				case MessagesServiceTypeAIM:
					Param7.appendIntValue(0);
					break;
				case MessagesServiceTypeBonjour:
					Param7.appendIntValue(1);
					break;
				case MessagesServiceTypeJabber:
					Param7.appendIntValue(2);
					break;
				case MessagesServiceTypeIMessage:
					Param7.appendIntValue(3);
					break;
				default:
					Param7.appendIntValue(-1);
					break;
			}

			switch ([[statusArray objectAtIndex:i]enumCodeValue])
			{
				case MessagesMyStatusAway:
					Param5.appendIntValue(0);
					break;
				case MessagesMyStatusAvailable:
					Param5.appendIntValue(1);
					break;
				case MessagesMyStatusOffline:
					Param5.appendIntValue(2);
					break;
				case MessagesMyStatusInvisible:
					Param5.appendIntValue(3);
					break;
				default:
					Param5.appendIntValue(-1);
					break;
			}
		}
	}

	Param1.toParamAtIndex(pParams, 1);
	Param2.toParamAtIndex(pParams, 2);
	Param3.toParamAtIndex(pParams, 3);
	Param4.toParamAtIndex(pParams, 4);
	Param5.toParamAtIndex(pParams, 5);
	Param6.toParamAtIndex(pParams, 6);
	Param7.toParamAtIndex(pParams, 7);
}

void MESSAGE_SERVICE_BUDDY_LIST(PA_PluginParameters params)
{
	PackagePtr pParams = (PackagePtr)params->fParameters;
	
	C_TEXT Param1;
	ARRAY_TEXT Param2;
	ARRAY_TEXT Param3;
	ARRAY_TEXT Param4;
	ARRAY_LONGINT Param5;
	ARRAY_TEXT Param6;
	ARRAY_LONGINT Param7;

	//$8
	PA_Variable Param8 = PA_CreateVariable(eVK_ArrayPicture);
//	PA_Variable Param8 = *((PA_Variable*) pParams[7]);
	
//	switch (Param8.fType)
//	{
//		case eVK_ArrayPicture:
//			break;
//		case eVK_Undefined:
//			PA_ClearVariable(&Param8);
//			Param8 = PA_CreateVariable(eVK_ArrayPicture);
//			break;
//		default:
//			break;
//	}
	
//	PA_ResizeArray(&Param8, 0);
	
	Param1.fromParamAtIndex(pParams, 1);

	if((Messages) && ([Messages isRunning]))
	{
		NSString *serviceId = Param1.copyUTF16String();
		SBElementArray *services = [Messages services];
		MessagesService *service = (MessagesService *)[services objectWithID:serviceId];
		
		if([service id])
		{
			SBElementArray *buddies = [service buddies];
			NSArray *idArray = [buddies arrayByApplyingSelector:@selector(id)];
			NSArray *nameArray = [buddies arrayByApplyingSelector:@selector(name)];
			NSArray *handleArray = [buddies arrayByApplyingSelector:@selector(handle)];
			NSArray *statusArray = [buddies arrayByApplyingSelector:@selector(status)];
			NSArray *statusMessageArray = [buddies arrayByApplyingSelector:@selector(statusMessage)];
			NSArray *idleTimeArray = [buddies arrayByApplyingSelector:@selector(idleTime)];
			NSArray *imageArray = [buddies arrayByApplyingSelector:@selector(image)];

			Param2.setSize(1);
			Param3.setSize(1);
			Param4.setSize(1);
			Param5.setSize(1);
			Param6.setSize(1);
			Param7.setSize(1);
			PA_ResizeArray(&Param8, 1);
			
			for(NSUInteger i = 0; i < [buddies count]; ++i)
			{
				Param2.appendUTF16String([idArray objectAtIndex:i]); // string
				Param3.appendUTF16String([nameArray objectAtIndex:i]); // string
				Param4.appendUTF16String([handleArray objectAtIndex:i]); // string
				Param6.appendUTF16String([statusMessageArray objectAtIndex:i]); // string
				Param7.appendIntValue([[idleTimeArray objectAtIndex:i]intValue]); // NSInteger
				
				switch ([[statusArray objectAtIndex:i]enumCodeValue])
				{
					case MessagesAccountStatusAvailable:
						Param5.appendIntValue(0);
						break;
					case MessagesAccountStatusAway:
						Param5.appendIntValue(1);
						break;
					case MessagesAccountStatusOffline:
						Param5.appendIntValue(2);
						break;
					case MessagesAccountStatusInvisible:
						Param5.appendIntValue(3);
						break;
					case MessagesAccountStatusIdle:
						Param5.appendIntValue(4);
						break;
					case MessagesAccountStatusUnknown:
						Param5.appendIntValue(5);
						break;
					default:
						Param5.appendIntValue(-1);
						break;
				}
				
				PA_ResizeArray(&Param8, i + 1);
				
				NSImage *image = [[buddies objectAtIndex:i]image];
				if(image)//can be nil
				{
					NSData *data = [image TIFFRepresentation];
					if(data)
					{
						PA_Picture picture = PA_CreatePicture((void*)[data bytes], [data length]);
						PA_SetPictureInArray(Param8, i + 1, picture);
					}
					
				}
	
			}
		
		}
		
		[serviceId release];
	}

	Param2.toParamAtIndex(pParams, 2);
	Param3.toParamAtIndex(pParams, 3);
	Param4.toParamAtIndex(pParams, 4);
	Param5.toParamAtIndex(pParams, 5);
	Param6.toParamAtIndex(pParams, 6);
	Param7.toParamAtIndex(pParams, 7);
	
	PA_SetVariableParameter(params, 8, Param8, 0);
}

void MESSAGE_SERVICE_LOGIN(sLONG_PTR *pResult, PackagePtr pParams)
{
	C_TEXT Param1;

	Param1.fromParamAtIndex(pParams, 1);

	if((Messages) && ([Messages isRunning]))
	{
		NSString *serviceId = Param1.copyUTF16String();
		SBElementArray *services = [Messages services];
		MessagesService *service = (MessagesService *)[services objectWithID:serviceId];
		
		if([service id])
		{
			[service logIn];
		}
		
		[serviceId release];
		
	}

}

void MESSAGE_SERVICE_LOGOUT(sLONG_PTR *pResult, PackagePtr pParams)
{
	C_TEXT Param1;

	Param1.fromParamAtIndex(pParams, 1);
	
	if((Messages) && ([Messages isRunning]))
	{
		NSString *serviceId = Param1.copyUTF16String();
		SBElementArray *services = [Messages services];
		MessagesService *service = (MessagesService *)[services objectWithID:serviceId];
		
		if([service id])
		{
			[service logOut];
		}
		
		[serviceId release];
		
	}

}

#pragma mark -

void MESSAGE_SEND(sLONG_PTR *pResult, PackagePtr pParams)
{
	C_TEXT Param1;
	C_TEXT Param2;

	Param1.fromParamAtIndex(pParams, 1);
	Param2.fromParamAtIndex(pParams, 2);

	if((Messages) && ([Messages isRunning]))
	{
		NSString *buddyId = Param1.copyUTF16String();
		SBElementArray *buddies = [Messages buddies];
		MessagesBuddy *buddy = (MessagesBuddy *)[buddies objectWithID:buddyId];
		
		if(buddy)
		{
			NSString *message = Param2.copyUTF16String();
			[Messages send:message to:buddy];
			[message release];
		}
		
		[buddyId release];
		
	}
	
}

