import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@11/dist/mermaid.esm.min.mjs';

// Fungsi untuk scan otomatis icon apa saja yang dipanggil di halaman ini
const detectIcons = (prefix) => {
    // Ambil semua elemen mermaid di halaman
    const elements = document.querySelectorAll('.mermaid');
    const foundIcons = new Set();

    // Regex untuk mencari pola "prefix:nama-icon"
    // Contoh: logos:aws-ec2 atau material:sensors
    const regex = new RegExp(`${prefix}:([a-zA-Z0-9\\-]+)`, 'g');

    elements.forEach(el => {
        const text = el.textContent;
        let match;
        while ((match = regex.exec(text)) !== null) {
            foundIcons.add(match[1]); // Masukkan nama icon ke Set (biar gak duplikat)
        }
    });

    return Array.from(foundIcons);
};

// Logic Loader Dinamis
const createLoader = (prefix, collectionName) => {
    return () => {
        const iconsToLoad = detectIcons(prefix);

        if (iconsToLoad.length === 0) {
            return Promise.resolve({});
        }

        const iconString = iconsToLoad.join(',');
        const url = `https://api.iconify.design/${collectionName}.json?icons=${iconString}`;

        return fetch(url).then(res => res.json());
    };
};

// Register Pack dengan Loader Cerdas
mermaid.registerIconPacks([
    {
        name: 'carbon', 
        loader: createLoader('carbon', 'carbon')
    },
    {
        name: 'material-symbols', 
        loader: createLoader('material-symbols', 'material-symbols')
    }
]);

window.mermaid = mermaid;