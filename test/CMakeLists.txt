# Test segmentation tile map
nav2_add_gtest(test_segmentation_tile_map
  test_segmentation_tile_map.cpp
)
target_link_libraries(test_segmentation_tile_map
  semantic_segmentation_layer
)
