#include "Player.h"

Player::Player(int skin) {
    // Initialize spacecraft shape and properties
    sf::RectangleShape spacecraftTemp(sf::Vector2f(140.0f, 110.0f));  // Updated spacecraft size
    sf::RectangleShape beamTemp(sf::Vector2f(50.0f, 50.0f));
    sf::RectangleShape health3Temp(sf::Vector2f(100.0f, 33.3f));
    sf::RectangleShape health2Temp(sf::Vector2f(66.6f, 33.3f));
    sf::RectangleShape health1Temp(sf::Vector2f(33.3f, 33.3f));

    health1 = health1Temp, health2 = health2Temp, health3 = health3Temp;
    spacecraft = spacecraftTemp, beam = beamTemp;
    spacecraft.setOrigin(70.0f, 55.0f);  // Adjust origin for new size (center of the spacecraft)
    spacecraft.setPosition(450.0f, 470.0f);
    beam.setOrigin(25.0f, 25.0f);
    health3.setPosition(10, 10);
    health2.setPosition(10, 10);
    health1.setPosition(10, 10);

    // Load sound effects
    if (!bulletBuffer.loadFromFile("Sounds/bulletSound.oga")) {
        // Error handling (optional)
    }
    bulletSound.setBuffer(bulletBuffer);

    if (!explosionBuffer.loadFromFile("Sounds/explosion.wav")) {
        // Error handling (optional)
    }
    explosionSound.setBuffer(explosionBuffer);

    // Load textures based on selected skin
    switch (skin) {
        case 1:
            spacecrafttexture.loadFromFile("images/spacecraft1.png");
            break;
        case 2:
            spacecrafttexture.loadFromFile("images/spacecraft2.png");
            break;
        case 3:
            spacecrafttexture.loadFromFile("images/spacecraft3.png");
            break;
        default:  // Fallback to default skin
            spacecrafttexture.loadFromFile("images/spacecraft.png");
    }

    // Load common textures
    beamtexture.loadFromFile("images/beam1.png");
    health1texture.loadFromFile("images/health1.png");
    health2texture.loadFromFile("images/health2.png");
    health3texture.loadFromFile("images/health3.png");

    // Set textures to shapes
    spacecraft.setTexture(&spacecrafttexture);
    beam.setTexture(&beamtexture);
    health1.setTexture(&health1texture);
    health2.setTexture(&health2texture);
    health3.setTexture(&health3texture);

    // Initialize gameplay variables
    spaceraftX = 450.0f, spaceraftY = 470.0f;
    health = 3.0f;
    beamMove = false;
    beam_respawn = false;
    beamX = 0.0f, beamY = 0.0f;
}

void Player::movement() {
    // Adjusted spacecraft movement boundaries based on new size
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && spaceraftX < 1017.0f)
        spacecraft.move(0.4f, 0.0f), spaceraftX += 0.4f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && spaceraftX > 50.0f)
        spacecraft.move(-0.4f, 0.0f), spaceraftX -= 0.4f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && spaceraftY < 500.0f)
        spacecraft.move(0.0f, 0.2f), spaceraftY += 0.2f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && spaceraftY > 0.0f)
        spacecraft.move(0.0f, -0.4f), spaceraftY -= 0.4f;
}

void Player::beamShoot() {
    if (beamY <= 0.0f || beam_respawn)
        beamMove = false, beam_respawn = false, beamX = 0.0f, beamY = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !beamMove) {
        beam.setPosition(spaceraftX, spaceraftY);
        beamY = spaceraftY;
        beamX = spaceraftX;
        beamMove = true;
        bulletSound.play();  // Add this line
    }

    if (beamMove)
        beam.move(0.0f, -2.0f), beamY -= 2.0f;
}

bool Player::eggStrike(float X, float Y, float damage) {
    if (spaceraftY <= Y && (spaceraftY + 110.0f) >= Y)  // Adjusted to spacecraft's new size
        if ((spaceraftX - 70.0f) <= X && (spaceraftX + 70.0f) >= X) {  // Adjusted for new size
            float oldHealth = health;
            health -= damage;
            if (oldHealth > 2.0f && health <= 2.0f) {  // First heart destroyed (3 → 2)
                explosionSound.play();
            }
            else if (oldHealth > 1.0f && health <= 1.0f) {  // Second heart destroyed (2 → 1)
                explosionSound.play();
            }
            else if (oldHealth > 0.0f && health <= 0.0f) {  // Final heart destroyed (1 → 0)
                explosionSound.play();
            }

            return true;
        }
    return false;
}

bool Player::DisplayHealth3() {
    if (health > 2.0f) return true;
    else return false;
}

bool Player::DisplayHealth2() {
    if (health > 1.0f && health <= 2.0f) return true;
    else return false;
}

bool Player::DisplayHealth1() {
    if (health <= 1.0f && health >= 0.0f) return true;
    else return false;
}

Player::~Player(void) {
}
