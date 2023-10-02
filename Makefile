NAME	= miniRT

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

INCLUDES	= -I ./includes/ \
			  -I ./lib/minilibx/ \
			  -I ./lib/libft/includes

LIBS		= -L ./lib/libft -lft \
			  -L ./lib/minilibx/ -lmlx -lm -lXext -lX11 -lz

LIBFT = ./lib/libft/libft.a

SRC	=	sources/matrix/matrix.c \
		sources/objects/cylinder.c \
		sources/objects/free_object.c \
		sources/objects/object.c \
		sources/objects/plane.c \
		sources/objects/sphere.c \
		sources/parsing/color_handler.c \
		sources/parsing/coordinates_handler.c \
		sources/parsing/errors_validation.c \
		sources/parsing/free_rt.c \
		sources/parsing/get_scene.c \
		sources/parsing/is_btwen_range.c \
		sources/parsing/is_double.c \
		sources/parsing/scene_validation.c \
		sources/parsing/utils_validations.c \
		sources/parsing/validate_angle.c \
		sources/parsing/validate_orientation.c \
		sources/ray_tracer/hit.c \
		sources/ray_tracer/intersect_cylinder.c \
		sources/ray_tracer/intersection.c \
		sources/ray_tracer/intersect_plane.c \
		sources/ray_tracer/intersect_sphere.c \
		sources/ray_tracer/light.c \
		sources/ray_tracer/lighting.c \
		sources/ray_tracer/lighting_utils.c \
		sources/ray_tracer/material.c \
		sources/ray_tracer/normal_at.c \
		sources/ray_tracer/ray.c \
		sources/ray_tracer/reflect_vector.c \
		sources/ray_tracer/set_transform.c \
		sources/ray_tracer/transform_ray.c \
		sources/shadow/shadow.c \
		sources/transformations/rotation.c \
		sources/transformations/scaling.c \
		sources/transformations/translation.c \
		sources/tuples/tuples.c \
		sources/world/camera.c \
		sources/world/color_at.c \
		sources/world/create_world.c \
		sources/world/intersect_world.c \
		sources/world/prepare_computations.c \
		sources/world/ray_for_pixel.c \
		sources/world/render.c \
		sources/world/shade_hit.c \
		sources/world/view_transform.c \
		sources/world/world_utils.c \
		sources/matrix/inverting_matrices/cofactor.c \
		sources/matrix/inverting_matrices/determinants.c \
		sources/matrix/inverting_matrices/inverse.c \
		sources/matrix/inverting_matrices/minor.c \
		sources/matrix/inverting_matrices/spotting_submatrices.c \
		sources/matrix/operations/comparing_matrix.c \
		sources/matrix/operations/multiply_matrix.c \
		sources/matrix/operations/multiply_matrix_tuple.c \
		sources/matrix/operations/transposing_matrix.c \
		sources/parsing/elements/pl_rotation.c \
		sources/parsing/elements/validate_a.c \
		sources/parsing/elements/validate_c.c \
		sources/parsing/elements/validate_cy.c \
		sources/parsing/elements/validate_l.c \
		sources/parsing/elements/validate_pl.c \
		sources/parsing/elements/validate_sp.c \
		sources/tuples/colors/color.c \
		sources/tuples/colors/multiply_colors.c \
		sources/tuples/operations/addition.c \
		sources/tuples/operations/cross.c \
		sources/tuples/operations/dot.c \
		sources/tuples/operations/magnitude.c \
		sources/tuples/operations/multiply_divide.c \
		sources/tuples/operations/negative.c \
		sources/tuples/operations/normalization.c \
		sources/tuples/operations/subtract.c \
		sources/ft_atof.c \
		sources/handle_mlx.c \
		sources/main.c \
		sources/scene.c \
		sources/utils.c

OBJ_DIR = obj

OBJS	= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# BASICS #######################################################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo building $(NAME) binary

clean:
	@echo removing $(NAME) objects
	@rm -rf $(OBJ_DIR)

	@echo cleaning libft intermediate files
	@make -sC ./lib/libft/ clean

fclean: clean
	@echo removing $(NAME) binary
	@rm -f $(NAME)

	@echo cleaning libft library file
	@make -sC ./lib/libft/ fclean

re: fclean all

# LIBS #########################################################################

$(LIBFT):
	@echo building libft
	@make -sC ./lib/libft/

# AUXILIARIES ##################################################################

$(OBJ_DIR)/%.o: %.c
	@echo compiling $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) $< -c -o $@

################################################################################

.PHONY: all clean fclean re
