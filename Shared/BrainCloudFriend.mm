//
//  BrainCloudFriend.m
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-10.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#import "BrainCloudFriend.hh"

#include "BrainCloudClient.h"
#include "BrainCloudCallback.hh"

@implementation BrainCloudFriend

- (void)getFriendProfileInfoForExternalId:(NSString *)externalId
                        authenicationType:(NSString *)authenticationType
                          completionBlock:(BCCompletionBlock)cb
                     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                 cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getFriendService()
        ->getFriendProfileInfoForExternalId([externalId UTF8String],
                                            [authenticationType UTF8String],
                                            new BrainCloudCallback(cb, ecb, cbObject));
}

- (void) getExternalIdForProfileId:(NSString *)profileId
                authenticationType:(NSString *)authenticationType
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()
        ->getFriendService()
        ->getExternalIdForProfileId([profileId UTF8String],
                                    [authenticationType UTF8String],
                                    new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readFriendEntity:(NSString *)entityId
                friendId:(NSString *)friendId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getFriendService()->readFriendEntity(
        [entityId UTF8String], [friendId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readFriendsEntities:(NSString *)entityType
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getFriendService()->readFriendsEntities(
        [entityType UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readFriendsWithApplication:(bool)includeSummaryData
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getFriendService()->readFriendsWithApplication(
        includeSummaryData, new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)readFriendPlayerState:(NSString *)friendId
              completionBlock:(BCCompletionBlock)cb
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getFriendService()->readFriendPlayerState(
        [friendId UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)updateSummaryFriendData:(NSString *)jsonSummaryData
                completionBlock:(BCCompletionBlock)cb
           errorCompletionBlock:(BCErrorCompletionBlock)ecb
                       cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getFriendService()->updateSummaryFriendData(
        [jsonSummaryData UTF8String], new BrainCloudCallback(cb, ecb, cbObject));
}

- (void)findPlayerByName:(NSString *)searchText
              maxResults:(int)maxResults
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject
{
    BrainCloud::BrainCloudClient::getInstance()->getFriendService()->findPlayerByName(
        [searchText UTF8String], maxResults, new BrainCloudCallback(cb, ecb, cbObject));
}

@end