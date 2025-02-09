const attendanceOutput = document.getElementById('attendanceOutput');
const homeworkOutput = document.getElementById('homeworkOutput');
const announcementOutput = document.getElementById('announcementOutput');
const studentOutput = document.getElementById('studentOutput');

let students = [];

function toggleSection(sectionId) {
    const sections = document.querySelectorAll('.section');
    sections.forEach(section => {
        if (section.id === sectionId) {
            section.classList.toggle('hidden');
        } else {
            section.classList.add('hidden');
        }
    });
}

function trackAttendance() {
    const studentId = document.getElementById('attendanceId').value;
    const present = document.getElementById('attendanceStatus').value === 'true';
    attendanceOutput.innerHTML += `<p>Tracked Attendance: Student ID: ${studentId}, Present: ${present}</p>`;
}

function assignHomework() {
    const title = document.getElementById('homeworkTitle').value;
    const description = document.getElementById('homeworkDescription').value;
    homeworkOutput.innerHTML += `<p>Assigned Homework: Title: ${title}, Description: ${description}</p>`;
}

function postAnnouncement() {
    const message = document.getElementById('announcementMessage').value;
    announcementOutput.innerHTML += `<p>Posted Announcement: ${message}</p>`;
}

function addStudent() {
    const name = document.getElementById('studentName').value;
    const id = document.getElementById('studentId').value;
    students.push({ name, id });
    studentOutput.innerHTML += `<p>Added Student: ${name}, ID: ${id}</p>`;
}