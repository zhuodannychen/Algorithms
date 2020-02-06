di = [0, 0, -1, 1]
dj = [1, -1, 0, 0]

# r, c is starting position
# R, C grid dimension
# grid is actual grid
# color1 is the color your trying to match
# color2 is new color

def floodfill(r, c, R, C, grid, color1, color2):
    if r < 0 or r >= R or c < 0 or c >= C:
        return 0
    if grid[r][c] != color1:
        return 0
    ans = 1
    grid[r][c] = color2
    for i in range(4):
        ans += floodfill(r + di[i], c + dj[i], R, C, grid, color1, color2)
    return ans
