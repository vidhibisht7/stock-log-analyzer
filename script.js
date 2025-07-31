function loadOutput() {
  const company = document.getElementById("companyInput").value.trim();

  if (!company) {
    alert("Please enter a company name.");
    return;
  }

  fetch("output.txt")
    .then((response) => {
      if (!response.ok) {
        throw new Error("Network response was not ok.");
      }
      return response.text();
    })
    .then((data) => {
      document.getElementById("outputContainer").innerText = data;
    })
    .catch((error) => {
      document.getElementById("outputContainer").innerText = "Error loading output.";
      console.error(error);
    });
}
