const iconPrefixes = {
  carbon: "carbon",
  "material-symbols": "material-symbols",
  logos: "logos",
  boxicons: "boxicons",
  ic: "ic",
};

const detectIcons = (prefix) => {
  const elements = document.querySelectorAll(".mermaid");
  const foundIcons = new Set();
  const regex = new RegExp(`${prefix}:([a-zA-Z0-9\\-]+)`, "g");

  elements.forEach((element) => {
    const text = element.textContent;
    let match;

    while ((match = regex.exec(text)) !== null) {
      foundIcons.add(match[1]);
    }
  });

  return Array.from(foundIcons);
};

const createLoader = (prefix, collectionName) => {
  return () => {
    const iconsToLoad = detectIcons(prefix);

    if (iconsToLoad.length === 0) {
      return Promise.resolve({});
    }

    const iconString = iconsToLoad.join(",");
    const url = `https://api.iconify.design/${collectionName}.json?icons=${iconString}`;

    return fetch(url).then((response) => response.json());
  };
};

const registerIconPacks = (mermaid) => {
  if (!mermaid || typeof mermaid.registerIconPacks !== "function") {
    return;
  }

  if (mermaid.__aiotIconPacksRegistered) {
    return;
  }

  mermaid.registerIconPacks(
    Object.entries(iconPrefixes).map(([prefix, collectionName]) => ({
      name: prefix,
      loader: createLoader(prefix, collectionName),
    })),
  );

  mermaid.__aiotIconPacksRegistered = true;
};

if (window.mermaid) {
  registerIconPacks(window.mermaid);
} else {
  let mermaidInstance;

  Object.defineProperty(window, "mermaid", {
    configurable: true,
    get() {
      return mermaidInstance;
    },
    set(value) {
      mermaidInstance = value;
      registerIconPacks(value);
    },
  });
}
