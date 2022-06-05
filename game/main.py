from pickle import REDUCE
import secrets
import pygame
import random

FPS = 60
WIDTH = 500
HEIGHT = 600

WHITE = (255,255,255)
BLACK = (0,0,0)
GREEN = (0,255,0)
BLUE = (0,0,255)
YELLO = (255,255,0)
RED = (255,0,0)

# game initialize and create a window
pygame.init()
screen = pygame.display.set_mode((WIDTH,HEIGHT))
pygame.display.set_caption("First Game")
clock = pygame.time.Clock()

backgroung_img = pygame.image.load("/home/chiu/Documents/game/space.png").convert()
airplain_img = pygame.image.load(r"/home/chiu/Documents/game/airplain.png").convert()
bullet_img = pygame.image.load("/home/chiu/Documents/game/bullet.png").convert()
rock_img = pygame.image.load("/home/chiu/Documents/game/rock.png").convert()

font_name = pygame.font.match_font('arial')

def draw_text(surf, text, size, x, y):
    font = pygame.font.Font(font_name, size)
    text_surface =  font.render(text, True, WHITE)
    text_rect = text_surface.get_rect()
    text_rect.centerx = x
    text_rect.top = y
    surf.blit(text_surface, text_rect)



class Player(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.transform.scale(airplain_img, (80,80))
        self.image.set_colorkey(BLACK)
        self.rect = self.image.get_rect()
        self.radius = 39 
        # pygame.draw.circle(self.image, RED, self.rect.center, self.radius)
        self.rect.centerx = WIDTH/2
        self.rect.bottom = HEIGHT - 10
        self.speedx = 3
        self.speedy = 3
        self.health = 100

    def update(self):
        key_pressed = pygame.key.get_pressed()
        if key_pressed[pygame.K_RIGHT]:
            self.rect.x += self.speedx
        if key_pressed[pygame.K_LEFT]:
            self.rect.x -= self.speedx
        if key_pressed[pygame.K_DOWN]:
            self.rect.y += self.speedy
        if key_pressed[pygame.K_UP]:
            self.rect.y -= self.speedy
        
        if self.rect.right > WIDTH - 10:
            self.rect.right = WIDTH - 10
        if self.rect.left < 10:
            self.rect.left = 10
        if self.rect.bottom > HEIGHT - 10:
            self.rect.bottom = HEIGHT - 10
        if self.rect.top < 400:
            self.rect.top = 400
        
    def shoot(self):
        bullet = Bullet(self.rect.centerx, self.rect.top)
        all_sprites.add(bullet)
        bullets.add(bullet)

class Rock(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.transform.scale(rock_img, (50,80))
        self.image.set_colorkey(BLACK)
        self.rect = self.image.get_rect()
        self.radius = int(self.rect.width / 2)
        # pygame.draw.circle(self.image, RED, self.rect.center, self.radius)
        self.rect.x = random.randrange(0, WIDTH - self.rect.width)
        self.rect.y = random.randrange(-100, -40 )
        self.speedy = random.randrange(2, 10)
        self.speedx = random.randrange(-3, 3)

    def update(self):
        self.rect.y += self.speedy
        self.rect.x += self.speedx
        if self.rect.top > HEIGHT or self.rect.left < 0 or self.rect.right > WIDTH:
            self.rect.x = random.randrange(0, WIDTH - self.rect.width)
            self.rect.y = random.randrange(-100, -40)
            self.speedy = random.randrange(2, 10)
            self.speedx = random.randrange(-3, 3)
            
class Bullet(pygame.sprite.Sprite):
    def __init__(self, x, y): 
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.transform.scale(bullet_img, (20,60)) 
        self.image.set_colorkey(BLACK)
        self.rect = self.image.get_rect()
        self.rect.centerx = x
        self.rect.bottom = y
        self.speedy = -10

    def update(self):
        self.rect.y += self.speedy
        if self.rect.y < 0:
            self.kill()

def new_rock():
        rock = Rock()
        all_sprites.add(rock)
        rocks.add(rock)

def draw_health(surf, hp, x, y):
    if hp < 0:
        hp = 0
    BAR_LENGTH = 100
    BAR_HEIGHT = 10
    fill = (hp/100)*BAR_LENGTH
    outline_rect = pygame.Rect(x, y, BAR_LENGTH, BAR_HEIGHT)
    fill_rect = pygame.Rect(x, y, fill, BAR_HEIGHT)
    pygame.draw.rect(surf, GREEN, fill_rect)
    pygame.draw.rect(surf, WHITE, outline_rect, 2)

def draw_init():
    
    draw_text(screen, "Hi", 64, WIDTH/2, HEIGHT/4)
    draw_text(screen, "move", 22, WIDTH/2, HEIGHT/2)
    draw_text(screen, "Press anything to start the game", 18, WIDTH/2, HEIGHT*2.5/2)
    pygame.display.update()
    waiting = True
    while waiting:
        clock.tick(FPS)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
            elif event.type == pygame.KEYUP:
                waiting = False

all_sprites = pygame.sprite.Group()
rocks = pygame.sprite.Group()
bullets = pygame.sprite.Group()
player = Player()
all_sprites.add(player)
for i in range(8):
    new_rock()

score = 0

# game loop
show_init = True
running = True
while running:
    if show_init:
        draw_init()
        show_init = False
    clock.tick(FPS)
    # get input
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False   
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                player.shoot()

    # update the game
    all_sprites.update()
    hits = pygame.sprite.groupcollide(rocks, bullets, True, True)
    for hit in hits:
        score += hit.radius
        new_rock()

    hits = pygame.sprite.spritecollide(player, rocks, True, pygame.sprite.collide_circle)
    for hit in hits:
        player.health -= hit.radius
        new_rock()
        if player.health <= 0:
            running = False

    # screen display  
    screen.fill(BLACK)
    screen.blit(backgroung_img, (0,0))
    all_sprites.draw(screen)
    draw_text(screen, str(score), 18, WIDTH/2, 10)
    draw_health(screen, player.health, 5, 10)
    pygame.display.update()

pygame.quit()