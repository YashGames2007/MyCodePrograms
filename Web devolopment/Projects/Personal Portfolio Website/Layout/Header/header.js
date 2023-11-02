function getPosition(string, substring, index) {
    return string.split(substring, index).join(substring).length;
}

typed_Elements = {};
page_elements = {};
pages = {
    "index.html": "Home",
    "projects.html": "Projects",
    "resources.html": "Resources",
    "downloads.html": "Downloads",
    "about.html": "About",
}


let url = window.location.pathname;
let filename = url.substring(url.lastIndexOf('/')+1);

if (url.includes(".html")) {
    url = url.slice(0, url.lastIndexOf("/")) + "/";
}
if (url.includes("Pages/")) {
    url = url.slice(0, url.lastIndexOf("Pages/"));
}



let addHeader = (name, id) => {
    typed_Elements[name] = new Typed(id, {
        strings: [],
		typeSpeed: 40,
		backSpeed: 10,
		fadeOut: true,
		backDelay: 1000,
        showCursor: (name==pages[filename])
	});
	page_elements[name] = document.querySelector(id);
    href = document.querySelector(id).parentElement.href;
    document.querySelector(id).parentElement.href = url + href.slice(getPosition(href, "/", 3)+1);
    
    
    
	page_elements[name].addEventListener("mouseenter", function () {
        typed_Elements[name].start();
	});
	page_elements[name].addEventListener("mouseleave", function () {
        typed_Elements[name].reset();
	});
}

setTimeout(() => {
    addHeader("Home", "#nav_home");
    addHeader("Projects", "#nav_projects");
    addHeader("Resources", "#nav_resources");
    addHeader("Downloads", "#nav_downloads");
    addHeader("About", "#nav_about");
    logo = document.getElementById("on-page-logo");
    if (logo != null) {
        src =logo.src;
        logo.src = url + src.slice(getPosition(src, "/", 3)+1);
    }
}, 500);


function onMenuClick() {
    var navbar = document.getElementById("navigation-bar");
    var responsive_class_name = "responsive";

    navbar.classList.toggle(responsive_class_name);
}

function switchTheme() {
    document.body.classList.toggle("dark");
    if (document.getElementById("dn").checked) {
        document.getElementById("home-logo").src = "./Graphics/home_page.png"
    }
    else {
        document.getElementById("home-logo").src = "./Graphics/home_page_light.png"
    }
}

/**
 * Home - Index Page
 * Tutorials/Resources - Written articles
 * Projects - Source Code
 * Downloads - PDF Notes
 * About - Personal Info
 */
