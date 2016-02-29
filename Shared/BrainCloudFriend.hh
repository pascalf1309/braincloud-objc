//
//  BrainCloudFriend.h
//  brainCloudClientObjc
//
//  Created by Hill, Bradley on 2015-08-10.
//  Copyright (c) 2015 bitHeads. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BrainCloudCompletionBlocks.hh"

@interface BrainCloudFriend : NSObject

/**
* Retrieves profile information for the specified user.
*
* Service Name - Friend
* Service Operation - GetFriendProfileInfoForExternalId
*
* @param externalId The friend's external id e.g. Facebook id
* @param authenticationType The authentication type of the friend id e.g. Facebook
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the callback
* {
*   "status":200,
*   "data": {
*     "playerId" : "17c7ee96-1b73-43d0-8817-cba1953bbf57",
*     "playerName" : "Donald Trump",
*     "email" : "donald@trumpcastle.com",
*     "playerSummaryData" : {},
*   }
* }
*/
- (void)getFriendProfileInfoForExternalId:(NSString *)externalId
                        authenicationType:(NSString *)authenticationType
                          completionBlock:(BCCompletionBlock)cb
                     errorCompletionBlock:(BCErrorCompletionBlock)ecb
                                 cbObject:(BCCallbackObject)cbObject;

/**
 * Retrieves the external ID for the specified user profile ID on the specified social platform.
 *
 * @param profileId Profile (player) ID.
 * @param authenticationType Associated authentication type.
 * @param completionBlock Block to call on return of successful server response
 * @param errorCompletionBlock Block to call on return of unsuccessful server response
 * @param cbObject User object sent to the completion blocks
 *
 * @return The JSON returned in the callback
 * {
 *    "status": 200,
 *    "data": {
 *        "externalId": "19e1c0cf-9a2d-4d5c-9a71-1b0f6asdfb4b"
 *    }
 * }
 */
- (void) getExternalIdForProfileId:(NSString *)profileId
                authenticationType:(NSString *)authenticationType
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject;

/**
* Returns a particular entity of a particular friend.
*
* Service Name - Friend
* Service Operation - ReadFriendEntity
*
* @param entityId Id of entity to retrieve.
* @param friendId Profile Id of friend who owns entity.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block
*/
- (void)readFriendEntity:(NSString *)entityId
                friendId:(NSString *)friendId
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

/**
* Returns entities of all friends optionally based on type.
*
* Service Name - Friend
* Service Operation - ReadFriendsEntities
*
* @param entityType Types of entities to retrieve.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block
*/
- (void)readFriendsEntities:(NSString *)entityType
            completionBlock:(BCCompletionBlock)cb
       errorCompletionBlock:(BCErrorCompletionBlock)ecb
                   cbObject:(BCCallbackObject)cbObject;

/**
* Returns list of friends with optional summary data.
*
* Service Name - Friend
* Service Operation - ReadFriendsWithApplication
*
* @param includeSummaryData Whether to include summary data
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block
*/
- (void)readFriendsWithApplication:(bool)includeSummaryData
                   completionBlock:(BCCompletionBlock)cb
              errorCompletionBlock:(BCErrorCompletionBlock)ecb
                          cbObject:(BCCallbackObject)cbObject;

/**
* Read a friend's player state.
*
* Service Name - PlayerState
* Service Operation - ReadFriendsPlayerState
*
* @param friendId Target friend
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*/
- (void)readFriendPlayerState:(NSString *)friendId
              completionBlock:(BCCompletionBlock)cb
         errorCompletionBlock:(BCErrorCompletionBlock)ecb
                     cbObject:(BCCallbackObject)cbObject;

/**
* Updates the "friend summary data" associated with the logged in player.
* Some operations will return this summary data. For instance the social
* leaderboards will return the player's score in the leaderboard along
* with the friend summary data. Generally this data is used to provide
* a quick overview of the player without requiring a separate API call
* to read their public stats or entity data.
*
* Note this API call pre-dates the shared player data api (public entity/stats)
* and thus usage for anything outside of social leaderboards should be
* deprecated.
*
* Service Name - PlayerState
* Service Operation - UpdateSummary
*
* @param jsonSummaryData A JSON string defining the summary data.
* For example:
* {
*   "xp":123,
*   "level":12,
*   "highScore":45123
* }
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*   "status":200,
*   "data":null
* }
*/
- (void)updateSummaryFriendData:(NSString *)jsonSummaryData
                completionBlock:(BCCompletionBlock)cb
           errorCompletionBlock:(BCErrorCompletionBlock)ecb
                       cbObject:(BCCallbackObject)cbObject;

/**
* Finds a list of players matching the search text by performing a substring
* search of all player names.
* If the number of results exceeds maxResults the message
* "Too many results to return." is received and no players are returned
*
* Service Name - Friend
* Service Operation - FindPlayerByName
*
* @param searchText The substring to search for. Minimum length of 3 characters.
* @param maxResults  Maximum number of results to return. If there are more the message
*                       "Too many results to return." is sent back instead of the players.
* @param completionBlock Block to call on return of successful server response
* @param errorCompletionBlock Block to call on return of unsuccessful server response
* @param cbObject User object sent to the completion blocks
*
* @return The JSON returned in the completion block is as follows:
* {
*     "status": 200,
*     "data": {
*         "matches": [
*         {
*             "profileId": "63d1fdbd-2971-4791-a248-f8cda1a79bba",
*             "playerSummaryData": null,
*             "profileName": "ABC"
*         }
*         ],
*         "matchedCount": 1
*     }
* }
*/
- (void)findPlayerByName:(NSString *)searchText
              maxResults:(int)maxResults
         completionBlock:(BCCompletionBlock)cb
    errorCompletionBlock:(BCErrorCompletionBlock)ecb
                cbObject:(BCCallbackObject)cbObject;

@end