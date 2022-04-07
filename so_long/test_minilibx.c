#include <mlx.h>

typedef struct s_data
{
    void    *img;
    char    *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

typedef struct s_vars
{
    void    *mlx;
    void    *mlx_win;
}   t_vars;

int mlx_close(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->mlx_win);
    return (0);
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int    add_shade(double distance, int color)
{
    int r;
    int g;
    int b;

    if (distance >= 0 && distance < 1)
    {
        r = ((color >> 16) & 0xFF) * distance;
        g = ((color >> 8) & 0xFF) * distance;
        b = (color & 0xFF) * distance;
        color =  (r << 16 | g << 8 | b);
    }
    return (color);
}

int    get_opposite(int color)
{
    int r;
    int g;
    int b;

    r = (color >> 16) & 0xFF;
    g = (color >> 8) & 0xFF;
    b = color & 0xFF;
    
    color = ((r ^ 255) << 16 | (g ^ 255) << 8 | (b ^ 255));
    return (color);
}

int main(void)
{
    t_vars  t_mlx;
    t_data  img1;
    t_data  img2;
    t_data  img3;
    int add_shade_color;
    int opposite_color;
    int i;
    int j;

    t_mlx.mlx = mlx_init();
    t_mlx.mlx_win = mlx_new_window(t_mlx.mlx, 1920, 1080, "Hello World!");
    img1.img = mlx_new_image(t_mlx.mlx, 1920, 1080);
    img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel, &img1.line_length, &img1.endian);
    img2.img = mlx_new_image(t_mlx.mlx, 1920, 1080);
    img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length, &img2.endian);
    img3.img = mlx_new_image(t_mlx.mlx, 1920, 1080);
    img3.addr = mlx_get_data_addr(img3.img, &img3.bits_per_pixel, &img3.line_length, &img3.endian);
    i = 0;
    while (i < 50)
    {
        j = 0;
        while (j < 50)
        {
            my_mlx_pixel_put(&img1, 50 + i, 50 + j, 0x0000FF00);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(t_mlx.mlx, t_mlx.mlx_win, img1.img, 100, 100);
    add_shade_color = add_shade(0.5, 0x0000FF00);
    opposite_color = get_opposite(0x0000FF00);
    i = 0;
    while (i < 50)
    {
        j = 0;
        while (j < 50)
        {
            if ((i * i) + (j * j) <= 1000)
            {
                my_mlx_pixel_put(&img2, 100 + i, 100 + j, add_shade_color);
                my_mlx_pixel_put(&img2, 100 - i, 100 + j, opposite_color);
                my_mlx_pixel_put(&img2, 100 + i, 100 - j, 0x000000FF);
                my_mlx_pixel_put(&img2, 100 - i, 100 - j, 0x000000FF);
            }
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(t_mlx.mlx, t_mlx.mlx_win, img2.img, 200, 100);
    mlx_hook(t_mlx.mlx_win, 2, 1L<<0, mlx_close, &t_mlx);
    mlx_loop(t_mlx.mlx);
}