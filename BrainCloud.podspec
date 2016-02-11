#
#  BrainCloud.podspec
#  BrainCloud
#
#  Created by Benoit Sarrazin on Feb 11, 2016.
#  Copyright (c) 2016 BitHeads Inc. All rights reserved.
#

Pod::Spec.new do |s|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.name     = "BrainCloud"
  s.version  = "0.0.1"
  s.summary  = "A short description of BrainCloud."
  s.homepage = "http://getbraincloud.com/"

  s.ios.deployment_target  = "6.0"
  s.osx.deployment_target  = "10.8"
  s.tvos.deployment_target = "9.0"

  # ―――  Spec License  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.license                = {:type => "Apache License, Version 2.0", :file => "LICENSE"}

  # ――― Author Metadata  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.authors                = {"Benoit Sarrazin" => "ben@bitheads.com"}
  s.social_media_url       = "https://twitter.com/braincloudbaas"

  # ――― Source Location ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.source                 = {:git => "https://github.com/getbraincloud/braincloud-objc.git", :tag => "0.0.1"}

  # ――― Source Code ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.header_mappings_dir    = 'Shared'
  s.public_header_files    = 'Shared/**/*.{h,hh}'
  s.private_header_files   = 'Shared/**/{BrainCloudCallback,TypeHelpers}.hh'
  s.source_files           = 'Shared/**/*.{hh,mm}'

  # ――― Project Linking ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.library                = "z"

  # ――― Project Settings ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #

  s.dependency 'BrainCloudCpp', '0.0.1'

end
