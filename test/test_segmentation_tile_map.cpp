// Copyright (c) 2026, Open Navigation LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License. Reserved.

#include "gtest/gtest.h"
#include "semantic_segmentation_layer/segmentation_tile_map.hpp"

TEST(TestSegmentationTileMap, test_world_index_conversions)
{
    SegmentationTileMap tile_map {0.25, 1.0};

    auto index = tile_map.worldToIndex(25, 25);
    EXPECT_EQ(index.x, 100);
    EXPECT_EQ(index.y, 100);

    auto coords = tile_map.indexToWorld(4, 4);
    EXPECT_NEAR(coords.x, 1.125, 1e-3);
    EXPECT_NEAR(coords.y, 1.125, 1e-3);
}

/**
 * Make sure that push function correctly sets the decay time for observation queues
 * since they don't set by themselves/by default which can lead to undefined behavior
 */
TEST(TestSegmentationTileMap, test_push_set_decay_time)
 {
    SegmentationTileMap tile_map {0.25, 1.0};

    TileObservation observation {1, 1.0, 1.0};
    TileIndex index {1, 1};

    tile_map.pushObservation(observation, index);

    /**
     * Since we cannot directly check the variable for decay time set within queue,
     * let's just test the decay behavior.
     */
    tile_map.purgeOldObservations(3.0);
    EXPECT_EQ(tile_map.size(), 0);
}
