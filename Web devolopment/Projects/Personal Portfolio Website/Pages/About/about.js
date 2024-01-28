const card = document.getElementById('hero-card');
let hover = false;

card.addEventListener('mouseenter', (e) => {
  hover=true;
});

card.addEventListener('mouseleave', (e) => {
  hover=false;
});

let rect = card.getBoundingClientRect();
let anchorX = rect.left + rect.width / 2;
let anchorY = rect.top + rect.height / 2;

function onChange(){
  rect = card.getBoundingClientRect();
  anchorX = rect.left + rect.width / 2;
  anchorY = rect.top + rect.height / 2;
}

document.body.addEventListener('resize', onChange);
window.addEventListener('resize', onChange);
document.addEventListener('resize', onChange);
document.addEventListener('scroll', onChange);

document.addEventListener('mousemove', (e) => { 
  if(hover){
  const mouseX = e.clientX;
  const mouseY = e.clientY;
  
  const angleRad = angle(mouseX, mouseY, anchorX, anchorY);
  const angleDeg = angleRad * 180 / Math.PI;
  const rotateX = Math.sin(angleRad) * 2;
  const rotateY = Math.cos(angleRad) * 2;
  
  card.style.setProperty("--rotateX", rotateX+"deg");
  card.style.setProperty("--rotateY", -1*rotateY+"deg");
  card.style.setProperty("--glow-rotation", angleDeg+"deg");
  }else{
  card.style.removeProperty("--rotateX");
  card.style.removeProperty("--rotateY");
  card.style.removeProperty("--glow-rotation");
  }
});

function angle(cx, cy, ex, ey){
  const dy = ey - cy;
  const dx = ex - cx;
  
  const rad = Math.atan2(dy, dx);
  return rad;
}