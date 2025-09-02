function pause(milliseconds) {
    return new Promise(resolve => setTimeout(resolve, milliseconds));
}

document.addEventListener("DOMContentLoaded", () => {
    const slider = document.querySelector('.slider');
    const allCards = document.querySelectorAll('.slider .item');

    let rotationY = 0;

    // Function to handle card click
    const handleCardClick = async (index) => {
        // Stop the rotation
        // slider.classList.toggle('paused');

        // Update the quantity to 0
        let quantity = 0; 
        let _break = 250

        const computedStyles = getComputedStyle(slider);
        if (computedStyles.getPropertyValue('--quantity')) {
            for (let i = 11; i > 0; i--) {
                slider.style.setProperty('--quantity', i)
                await pause(_break)
            }
            slider.style.removeProperty('--quantity');

            index += 1
        // Set the new positions for all cards
        allCards.forEach((card, i) => {
            i += 1
            // if (i == index)
            //     return
            if (i === 1)
            {
                card.style.setProperty('--position', index);
                card.style.display = 'none'
            }
            if (i == index) {
                card.style.setProperty('--position', 1); // Move clicked card to position 1
                card.style.width = '200%'
                card.style.paddingTop = 'calc(3.5 / 2.25* 200%)'
                // card.classList.add('extended');
            }
            else{
                card.style.display = 'none'
            }
        });
        }
        else
        {

            // Set the new positions for all cards
            allCards.forEach((card, i) => {
                card.style.display = 'block'
                card.style.width = '100%'
                card.style.paddingTop = 'calc(3.5 / 2.25* 100%)'
                // c.classList.remove('extended')               
            });

    
            for (let i = 1; i <= 11; i++) {
                slider.style.setProperty('--quantity', i)
                await pause(_break)
            }

            allCards.forEach((card, i) => {
                card.style.setProperty('--position', i+1); // Move clicked card to position 1
            });
        }
    };

    allCards.forEach((card, index) => {
        card.addEventListener("click", () => handleCardClick(index));
    });
});