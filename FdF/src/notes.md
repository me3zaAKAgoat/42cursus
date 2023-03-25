I have 4 components now.

start factors from 0 and keep scaling them until they reach certain thresholds

- to assure viual ease , keep the map under (max_z \* z_factor) / area threshold
  reduce the altitude of points until the factor is fulfilled
- to asure that the map isnt too big for the window, keep max\_(x or y) \* plane_scale_factor under a certain threshold
  reduce the plane scale factor until the factor is fulfilled
- to keep the map centered
  do an adjustement X and Y coordinate that scales with how big the map is
- to make sure the z axis isnt skyrocketing out of the window
  reduce the zscalefactor until a criteria is met


max_z * z_scale_factor