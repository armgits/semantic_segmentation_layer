# Test helper functions
nav2_add_gtest(test_utils
  test_utils.cpp
)
target_link_libraries(test_utils
  semantic_segmentation_layer
)

